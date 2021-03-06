#include <stdio.h>

// Created by bhargav on 17/11/20.
int multiply(int a, int b) {
    if (a > b) return multiply(b, a);
    else if (b != 0) return a + multiply(a, b - 1);
    else return 0;
}

int main() {
    int a = 0, b = 0;
    printf("Enter A & B: ");
    scanf("%d %d", &a, &b);
    printf("Product = %d\n", multiply(a, b));
    return 0;
}