#include <stdio.h>

int gcd(int a, int b) {
    if (b != 0) return gcd(b, a % b);
    else return a;
}

// Created by bhargav on 17/11/20.
int main() {
    int a = 0, b = 0;
    printf("Enter A & B: ");
    scanf("%d %d", &a, &b);
    printf("GCD = %d\n", gcd(a, b));
}
