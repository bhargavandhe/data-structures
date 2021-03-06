#include <stdio.h>

void main(){
    int ch, a, b, res=0;    
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    printf("Enter choice : ");
    scanf("%d", &ch);

    switch (ch){
    case 1:
        printf("Enter num 1 & num 2: ");
        scanf("%d %d", &a, &b);
        res = a+b;
        break;
    case 2:
        printf("Enter num 1 & num 2: ");
        scanf("%d %d", &a, &b);
        res = a-b;    
        break;
    case 3:
        printf("Enter num 1 & num 2: ");
        scanf("%d %d", &a, &b);
        res = a*b;  
        break;
    case 4:
        printf("Enter num 1 & num 2: ");
        scanf("%d %d", &a, &b);
        res = a/b;  
        break;
    default:
        printf("INVALID CHOICE!");
        break;
    }
    printf("Result = %d\n", res);
}