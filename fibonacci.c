#include <stdio.h>
// Created by bhargav on 17/11/20.

int fibonacci(int a) {
    if (a == 0) return 0;
    else if (a == 1) return 1;
    else return fibonacci(a - 1) + fibonacci(a - 2);
}

int main() {
    int limit;
    printf("Enter limit: ");
    scanf("%d", &limit);

    for (int i = 0; i < limit; i++)
        printf("%d\n", fibonacci(i));
    return 0;
}