#include <stdio.h>
#include <stdlib.h>
#define LEN 5

int stack[LEN];
int top=-1;

void display(){
    int i;
    printf("\nCurrent Stack status: \n");
    for (i = 0; i <= top; i++) printf("%d ", stack[i]);
    printf("\n");
}
void pop(){
    if (top == -1) printf("\nUnderflow, Cannot pop!\n");
    else {  
        printf("\nRemoved %d from stack!\n", stack[top]);
        stack[top] = 0;
        top -= 1;
        display();
    }
}
void push(){
    int e;
    if (top >= LEN-1) printf("\nOverflow, Cannot push!\n");
    else {
        printf("\nEnter an element to be inserted: ");
        scanf("%d", &e);
        stack[top+1] = e;        
        top += 1;
        printf("\nInserted %d to stack!", e);
        display();
    }
}

void main(){
    int ch;
    printf("Max length of stack = %d", LEN);

    while (1){
        printf("\nTop = %d\n", top);
        printf("\n1. POP\n2. Push\n3. Display\n4. Quit\n");
        printf("Enter Choice : ");
        scanf("%d", &ch);
        
        switch (ch){
        case 1:
            pop();
            break;
        case 2:
            push();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nInvalid choice, Please try again!\n");
            break;
        }
    }    
}