#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void add(int a, int b);
void subtract(int a, int b);
void multiply(int a, int b);
void divide(int a, int b);

// Function to demonstrate function pointers
void functionPointerExample(int a, int b, void (*operation)(int, int)) {
    operation(a, b);
}

// Callback function
void callbackExample(void (*callback)(void)) {
    printf("Callback function called.\n");
    callback();
}

// Example callback function
void exampleCallback() {
    printf("This is an example callback function.\n");
}

int main() {
    // Array of function pointers
    void (*operations[4])(int, int) = {add, subtract, multiply, divide};

    int a = 10, b = 5;

    // Using function pointers for different operations
    for (int i = 0; i < 4; i++) {
        functionPointerExample(a, b, operations[i]);
    }

    // Demonstrate callback function
    callbackExample(exampleCallback);

    return 0;
}

// Function definitions
void add(int a, int b) {
    printf("Add: %d + %d = %d\n", a, b, a + b);
}

void subtract(int a, int b) {
    printf("Subtract: %d - %d = %d\n", a, b, a - b);
}

void multiply(int a, int b) {
    printf("Multiply: %d * %d = %d\n", a, b, a * b);
}

void divide(int a, int b) {
    if (b != 0) {
        printf("Divide: %d / %d = %d\n", a, b, a / b);
    } else {
        printf("Divide: Division by zero error!\n");
    }
}