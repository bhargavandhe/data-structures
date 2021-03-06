// Created by bhargav on 17/12/20.
#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int data;
    struct queue *next;
} queue;

queue *front = NULL, *rear = NULL, *temp;

void display() {
    temp = front;
    if (front == NULL && rear == NULL) printf("Queue underflow\n");
    else {
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

void enqueue() {
    if (rear == NULL) {
        rear = (queue *) malloc(sizeof(queue));
        rear->next = NULL;

        printf("Enter data: ");
        scanf("%d", &rear->data);
        front = rear;
    } else {
        temp = (queue *) malloc(sizeof(queue));
        rear->next = temp;
        printf("Enter data: ");
        scanf("%d", &temp->data);
        temp->next = NULL;
        rear = temp;
    }
    printf("Inserted into queue\n");
}

void dequeue() {
    temp = front;
    if (temp == NULL) printf("Queue underflow\n");
    else if (temp->next != NULL) {
        front = front->next;
        free(temp);
    } else {
        free(temp);
        front = rear = NULL;
    }
    printf("Deleted from queue\n");
}

void showMenu() {
    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
                showMenu();
        }
    }
}

int main() {
    showMenu();
    return 0;
}