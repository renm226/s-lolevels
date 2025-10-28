
#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

using namespace std;

void demo_fork_and_wait() {
    cout << "\n=== fork() and wait() demo ===\n";
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return;
    }
    if (pid == 0) {
        // Child
        cout << "[child] PID=" << getpid() << ", PPID=" << getppid() << "\n";
        cout << "[child] Doing some work (sleep 2s)...\n";
        sleep(2);
        cout << "[child] Exiting with code 42\n";
        _exit(42); // child exits
    } else {
        // Parent
        cout << "[parent] PID=" << getpid() << ", created child PID=" << pid << "\n";
        int status;
        pid_t w = waitpid(pid, &status, 0);
        if (w == -1) {
            perror("waitpid");
            return;
        }
        if (WIFEXITED(status)) {
            cout << "[parent] Child " << pid << " exited with status " << WEXITSTATUS(status) << "\n";
        } else {
            cout << "[parent] Child " << pid << " terminated abnormally\n";
        }
    }
}

void demo_exec() {
    cout << "\n=== execvp() demo ===\n";
    cout << "This will fork a child and run 'ls -l' in the child using execvp().\n";
    pid_t pid = fork();
    if (pid == -1) { perror("fork"); return; }
    if (pid == 0) {
        // Child: replace image with /bin/ls -l
        char *argv[] = {(char*)"ls", (char*)"-l", (char*)nullptr};
        cout << "[child] running execvp(\"ls\", {\"ls\",\"-l\"})\n";
        // Note: execvp only returns on error
        if (execvp("ls", argv) == -1) {
            perror("execvp");
            _exit(1);
        }
    } else {
        // Parent
        int status;
        waitpid(pid, &status, 0);
        cout << "[parent] Child finished (exec demo).\n";
    }
}

void demo_pipe_parent_writes_child_reads() {
    cout << "\n=== pipe() demo (parent writes, child reads) ===\n";
    int fds[2];
    if (pipe(fds) == -1) { perror("pipe"); return; }

    pid_t pid = fork();
    if (pid == -1) { perror("fork"); return; }

    if (pid == 0) {
        // Child: read from pipe
        close(fds[1]); // close write end
        cout << "[child] reading from pipe...\n";
        // Make a buffer and read
        char buf[256];
        ssize_t n = read(fds[0], buf, sizeof(buf)-1);
        if (n == -1) { perror("read"); _exit(1); }
        buf[n] = '\0';
        cout << "[child] Received: \"" << buf << "\"\n";
        close(fds[0]);
        _exit(0);
    } else {
        // Parent: write to pipe
        close(fds[0]); // close read end
        string message = "Hello from parent PID " + to_string(getpid()) + "\n";
        cout << "[parent] writing to pipe: " << message;
        ssize_t w = write(fds[1], message.c_str(), message.size());
        if (w == -1) perror("write");
        close(fds[1]);
        waitpid(pid, nullptr, 0);
        cout << "[parent] child finished reading.\n";
    }
}

// Demonstrate zombie: child exits quickly; parent sleeps so child remains zombie.
// Demonstrate orphan: parent exits quickly; child continues -> init/adopted by PID 1.
void demo_zombie_and_orphan() {
    cout << "\n=== zombie & orphan demo (choose) ===\n";
    cout << "1) Create a zombie (child exits, parent sleeps)\n";
    cout << "2) Create an orphan (parent exits, child sleeps)\n";
    cout << "Select (1 or 2): ";
    int choice;
    if (!(cin >> choice)) {
        cin.clear();
        string dummy; getline(cin, dummy);
        cout << "Invalid input\n";
        return;
    }

    pid_t pid = fork();
    if (pid == -1) { perror("fork"); return; }

    if (pid == 0) {
        // Child
        if (choice == 1) {
            cout << "[child] I will exit immediately (become zombie until parent waits).\n";
            _exit(0);
        } else {
            cout << "[child] I'm child and will sleep for 10s. Parent will exit -> I become orphan.\n";
            for (int i = 0; i < 10; ++i) {
                cout << "[child] sleeping... (seconds left: " << 10 - i << ") my PPID=" << getppid() << "\n";
                sleep(1);
            }
            cout << "[child] after sleep my PPID=" << getppid() << "\n";
            _exit(0);
        }
    } else {
        // Parent
        if (choice == 1) {
            cout << "[parent] sleeping for 6 seconds WITHOUT wait() so child becomes zombie briefly.\n";
            sleep(6);
            // Now reap child
            int status;
            if (waitpid(pid, &status, WNOHANG) == 0) {
                cout << "[parent] child still running or zombie; now calling waitpid to reap.\n";
                waitpid(pid, &status, 0);
            }
            cout << "[parent] reaped child.\n";
        } else {
            cout << "[parent] exiting immediately so child becomes orphan (adopted by init/systemd PID 1).\n";
            _exit(0);
        }
    }
}

int main() {
    cout << "Process concepts demo — C++ (Linux/macOS)\n";
    while (true) {
        cout << "\nChoose a demo:\n";
        cout << "1) fork() + wait()\n";
        cout << "2) execvp() (child runs 'ls -l')\n";
        cout << "3) pipe() (parent writes, child reads)\n";
        cout << "4) zombie & orphan demo\n";
        cout << "0) exit\n";
        cout << "Enter choice: ";
        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            string dummy; getline(cin, dummy);
            cout << "Invalid input, try again.\n";
            continue;
        }
        switch (choice) {
            case 1: demo_fork_and_wait(); break;
            case 2: demo_exec(); break;
            case 3: demo_pipe_parent_writes_child_reads(); break;
            case 4: demo_zombie_and_orphan(); break;
            case 0: cout << "Bye!\n"; return 0;
            default: cout << "Unknown choice\n"; break;
        }
    }
    return 0;
}
