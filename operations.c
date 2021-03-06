#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define LEN 10

int stack[LEN];
int top = -1;
int res = 0;
void pop()
{
    stack[top] = 0;
    top -= 1;
}
void push(int n)
{
    stack[top + 1] = n;
    top += 1;
}
void add()
{
    while (top >= 1)
    {
        res = stack[top] + stack[top - 1];
        pop();
        pop();
        push(res);
    }
}
void sub()
{
    while (top >= 1)
    {
        res = abs(stack[top] - stack[top - 1]);
        pop();
        pop();
        push(res);
    }
}
void mul()
{
    while (top >= 1)
    {
        res = stack[top] * stack[top - 1];
        pop();
        pop();
        push(res);
    }
}
void divide()
{
    while (top >= 1)
    {
        res = (int)(stack[top] / stack[top - 1]);
        pop();
        pop();
        push(res);
    }
}
void power()
{
    while (top >= 1)
    {
        res = stack[top] ^ stack[top - 1];
        pop();
        pop();
        push(res);
    }
}
void main()
{
    char expression[30];
    printf("Enter an expression: ");
    fgets(expression, 30, stdin);
    for (int i = 0; i < 30; i++)
    {
        if (isdigit(expression[i]))
            push((int)expression[i] - 48);
        else if (expression[i] == '+')
            add();
        else if (expression[i] == '-')
            sub();
        else if (expression[i] == '*')
            mul();
        else if (expression[i] == '/')
            divide();
        else if (expression[i] == '^')
            power();
        else if (expression[i] == '\0')
            break;
    }
    printf("Result = %d\n", res);
}