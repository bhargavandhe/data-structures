#include <stdio.h>
int a, b, res=0;
int add(){
    printf("Enter num 1 & num 2: ");
    scanf("%d %d", &a, &b);
    return a+b;
}

int sub(){
    printf("Enter num 1 & num 2: ");
    scanf("%d %d", &a, &b);
    return a-b;
}

int mul(){
    printf("Enter num 1 & num 2: ");
    scanf("%d %d", &a, &b);
    return a*b;
}

int div(){
    printf("Enter num 1 & num 2: ");
    scanf("%d %d", &a, &b);
    return a/b;
}

void showMenu(){
    int ch;
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    printf("Enter choice : ");
    scanf("%d", &ch);

    switch (ch){
        case 1:
            res = add();
            break;
        case 2:
            res = sub();
            break;
        case 3:
            res = mul();
            break;
        case 4:
            res = div();
            break;
        default:
            printf("Invalid choice!");
            break;
    }    

    printf("Result = %d\n", res);
}

void main(){
    showMenu();
}