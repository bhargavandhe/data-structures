#include <stdio.h>
#include <stdlib.h>

// Created by bhargav on 17/11/20.
int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    else return n * factorial(n - 1);
}

int multiply(int a, int b) {
    if (a > b) return multiply(b, a);
    else if (b != 0) return a + multiply(a, b - 1);
    else return 0;
}

int fibonacci(int a) {
    if (a == 0) return 0;
    else if (a == 1) return 1;
    else return fibonacci(a - 1) + fibonacci(a - 2);
}

int gcd(int a, int b) {
    if (b != 0) return gcd(b, a % b);
    else return a;
}

void move(int size, char *from, char *to, char *aux) {
    //printf("MAX = %d\n", size);
    if (size == 1) {
        printf("Moving disk %d from %s to %s\n", size, from, to);
        return;
    }
    move(size - 1, from, aux, to);
    printf("Moved disk %d from %s to %s\n", size, from, to);
    move(size - 1, aux, to, from);
}

void showMenu() {
    int choice;
    printf("**Recursion Programs**\n");
    printf("1. Fibonacci\n2. Factorial\n3. GCD\n4. Multiplication of two Natural numbers\n5. Hanoi tower\n6. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    int n, a, b;
    switch (choice) {
        case 1:
            printf("Enter limit: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
                printf("%d\n", fibonacci(i));
            break;
        case 2:
            printf("Enter number for factorial: ");
            scanf("%d", &n);
            printf("Factorial = %d\n", factorial(n));
            break;
        case 3:
            printf("Enter A & B: ");
            scanf("%d %d", &a, &b);
            printf("GCD = %d\n", gcd(a, b));
            break;
        case 4:
            printf("Enter A & B: ");
            scanf("%d %d", &a, &b);
            printf("Product = %d\n", multiply(a, b));
            break;
        case 5:
            printf("Enter no. of disks: ");
            int size = 1;
            scanf("%d", &size);
            printf("\nCreated an SOURCE TOWER with %d disks\n\n", size);
            move(size, "SOURCE TOWER", "DESTINATION TOWER", "AUXILIARY TOWER");
            break;
        case 6:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
            showMenu();
            return;
    }
    showMenu();
}

int main() {
    showMenu();
    return 0;
}
