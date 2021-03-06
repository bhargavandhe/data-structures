// Created by bhargav on 21/11/20.
#include <stdio.h>
#include <ctype.h>

char stack[30];
int top = -1;

void push(char i) {
    stack[++top] = i;
}

char pop() {
    if (top == -1) return -1;
    else return stack[top--];
}

int getPriority(char sign) {
    if (sign == '(') return 0;
    if (sign == '+' || sign == '-') return 1;
    if (sign == '*' || sign == '/') return 2;
}

int main() {
    char expression[30];
    printf("Enter expression: ");
    scanf("%s", expression);
    int i = 0;
    while (expression[i] != '\0') {
        if (isalnum(expression[i])) printf("%c", expression[i]);
        else if (expression[i] == '(') push(expression[i]);
        else if (expression[i] == ')') {
            char x;
            while ((x = pop()) != '(') printf("%c", x);
        } else {
            while (getPriority(stack[top]) >= getPriority(expression[i])) printf("%c", pop());
            push(expression[i]);
        }
        i++;
    }
    while (top != -1) printf("%c", pop());
    printf("\n");
    return 0;
}
