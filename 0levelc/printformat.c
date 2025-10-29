#include <stdio.h>
int main(){
    int i =56;
    int j =45;
    int k =67;

    int l = i + j + k;
    //we can use fromat specifier to print variables so that we dont have to use multiple print statements
    //this is easy that calling variable or value in multiple print statements
    printf("The sum of %d, %d and %d is %d\n", i, j, k, l);
    return 0;
}