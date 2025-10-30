#include <stdio.h>
//print fahrenheit to celsius table
//for fahr = 0, 20, ..., 300


int main() {
    int fahr, celsius;
    int lower, upper, step;
    lower = 0;      //lower limit of temperature table
    upper = 300;    //upper limit
    step = 20;      //step size

    fahr = lower;
    while (fahr <= upper) {
        celsius = 100 * (fahr - 32) / 180;
        //this could also be 5/9
        //(fahr - 32) * 5 / 9  -converting to celsius
        printf("%3d %6d\n", fahr, celsius);
        //3 and 6 are formating minimum field width
        fahr = fahr + step;
    }
} 

