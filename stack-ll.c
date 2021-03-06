#include <stdio.h>
#include <stdlib.h>
// Created by bhargav on 05/11/20.

typedef struct node {
    int data;
    struct node *next;
} node;

node *top = NULL, *head = NULL;

void display() {
    node *temp;
    if (head == NULL) {
        system("clear");
        printf("Linked list is empty!\n");
    }
    else {
        temp = head;
        while (temp != NULL) {
            printf(" %d ", temp->data);
            if (temp->next != NULL) printf("->");
            temp = temp->next;
        }
        printf("\n");
    }
}

void pop() {
    if (top == NULL) printf("\nStack is empty");
    else {
        node *temp = head;
        while (temp->next != top)
            temp = temp->next;
        temp->next = NULL;
        free(top);
        top = temp;
    }
}

void push() {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    node *newp = malloc(sizeof(node));
    newp->data = data;
    newp->next = NULL;

    if (head == NULL) head = newp;
    else top->next = newp;
    top = newp;
}

int main() {
    while (1) {
        int choice;
        printf("1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                system("clear");
                printf("Pushed to stack\n");
                display();
                break;
            case 2:
                pop();
                system("clear");
                printf("Pop successful\n");
                display();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                system("clear");
                printf("Invalid choice\n");
        }
    }
}
