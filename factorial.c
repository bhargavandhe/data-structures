#include <stdio.h>

// Created by bhargav on 17/11/20.
int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    else return n * factorial(n - 1);
}

int main() {
    int n;
    printf("Enter number for factorial: ");
    scanf("%d", &n);
    printf("Factorial = %d\n", factorial(n));
    return 0;
}