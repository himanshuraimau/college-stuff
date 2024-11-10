#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


// Define a function pointer type for operations
typedef void (*Operation)(double *result, double a);

// Function to add two numbers
void add(double *result, double a) {
    *result += a;
}

// Function to subtract two numbers
void subtract(double *result, double a) {
    *result -= a;
}

// Function to multiply two numbers
void multiply(double *result, double a) {
    *result *= a;
}

// Function to divide two numbers
void divide(double *result, double a) {
    if (a != 0) {
        *result /= a;
    } else {
        printf("Warning: Division by zero encountered.\n");
    }
}

// Function to infer data type and convert to double
double parse_input(const char *input) {
    int has_decimal = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == '.') {
            has_decimal = 1;
        } else if (!isdigit(input[i]) && input[i] != '.') {
            printf("Invalid input. Only numbers are allowed.\n");
            exit(1);
        }
    }
    return atof(input);  // Convert string to double
}

// Function to compute result on generic numbers
void compute(double *arr, Operation op, int size, int is_subtract_or_divide) {
    double result = is_subtract_or_divide ? arr[0] : (op == multiply ? 1 : 0);
    for (int i = (is_subtract_or_divide ? 1 : 0); i < size; i++) {
        op(&result, arr[i]);
    }
    printf("Result of the operation: %.2f\n", result);
}

int main() {
    char input[50];
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    double arr[n];
    int choice;

    printf("Please enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%s", input);
        arr[i] = parse_input(input);
    }

    // Prompt user to select the operation
    printf("Select the operation to perform (1=add, 2=subtract, 3=multiply, 4=divide): ");
    scanf("%d", &choice);

    // Define operation functions
    Operation operations[] = {add, subtract, multiply, divide};

    // Perform computation based on user choice
    if (choice >= 1 && choice <= 4) {
        compute(arr, operations[choice - 1], n, choice == 2 || choice == 4);
    } else {
        printf("Invalid operation selected.\n");
    }

    return 0;
}
