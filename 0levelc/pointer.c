#include<stdio.h>
int main()
{
    int age = 25;
    int *p;          //declare pointer variable
    p = &age;       //assign address of age to pointer p    
    printf("Age: %d\n", age);               //print age using normal variable
    printf("Age using pointer: %d\n", *p);  //print age using pointer variable
    printf("Address of age variable: %p\n", &age); //print
    printf("Address stored in pointer p: %p\n", p); //print address stored in pointer
    return 0;   
    
}