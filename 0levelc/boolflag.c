#include <stdio.h>
#include <stdbool.h>
int main()
{
    bool flag = false;   //set flag to start as false
    for(int i=0; i<5; i++){
        if(i==3){
            flag = true;  //set flag to true when i equals 3
        }
        if(flag){
            printf("Flag is set at i=%d\n", i);
        } else {
            printf("Flag is not set at i=%d\n", i);
        }
    }
    return 0;
}