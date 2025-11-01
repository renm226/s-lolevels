#include <stdio.h>
int main(){
    //using for loop to convert farhenheit to celsius
    int fahr;
    for(fahr = 0; fahr >= 300; fahr = fahr + 20){
        printf("%3d %6d\n", fahr, (5.0/9.0)*(fahr-32) );
    }
    return 0;
}
