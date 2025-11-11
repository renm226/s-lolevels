#include <stdio.h>

int main()
{
    int flag =0;   //set flag to start as false
    for(int i=0; i<5; i++){
        if(i==3){
            flag =1;  //set flag to true when i equals 3
        }
        if(flag){
            printf("Flag is set at i=%d\n", i);
        } else {
            printf("Flag is not set at i=%d\n", i);
        }
    }


}