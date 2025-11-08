#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE *f = fopen("test.txt","w");
    if(!f){ perror("fopen"); return 1;}
    fprintf(f,"Hello World\n");
    fclose(f);

    f = fopen("test.txt","r");
    if(!f){ perror("fopen"); return 1;}
    char buf[100];
    while(fgets(buf,sizeof(buf),f))
        printf("%s",buf);
    fclose(f);
    return 0;
}
