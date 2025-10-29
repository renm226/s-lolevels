#include <stdio.h>

int main(void) {
    int i, j;
    float f;
    
    // Check return values of scanf for error handling
    printf("Enter the first integer value: ");
    if (scanf("%d", &i) != 1) {
        printf("Error: Invalid integer input\n");
        return 1;
    }

    printf("Enter a float value: ");
    if (scanf("%f", &f) != 1) {
        printf("Error: Invalid float input\n");
        return 1;
    }

    printf("Enter the second integer value: ");
    if (scanf("%d", &j) != 1) {
        printf("Error: Invalid integer input\n");
        return 1;
    }

    // Print both integers in one statement
    printf("The integer values entered are: %d and %d\n", i, j);
    printf("The float value entered is: %.2f\n", f);

    // Calculate sum
    int sum = i + (int)f + j;
    printf("The sum of %d, %.2f and %d is: %d\n", i, f, j, sum);
    
    return 0;  // Return 0 for successful execution
}