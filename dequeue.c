#include <stdio.h>
#include <stdlib.h>

#define MAX 10
// Created by bhargav on 12/12/20.
int queue[MAX];
int front = -1, rear = -1;

void create() {
    for (int i = 0; i < MAX; i++) queue[i] = 0;
    front = rear = -1;
    printf("Created a queue of SIZE = %d\n", MAX);
}

int isFull() {
    return ((front == 0 && rear == MAX - 1) || front == rear + 1) ? 1 : 0;
}

int isEmpty() {
    return (front == -1) ? 1 : 0;
}

void display() {
    for (int i = 0; i < MAX; ++i) printf("%d ", queue[i]);
    printf("\n");
}

void add() {
    display();
    printf("1. Add at beginning 2. Add at end\n");
    int choice;
    printf("Enter choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            // Add at beginning
            if (isFull()) printf("Queue is full!\n");
            else {
                int data;
                printf("Enter data: ");
                scanf("%d", &data);

                if (front == -1) front = rear = 0;
                else if (front == 0) front = MAX - 1;
                else front--;

                queue[front] = data;
                printf("Inserted %d at beginning of queue\n", data);
            }
            break;
        case 2:
            // Add at end
            if (isFull()) printf("Queue is full!\n");
            else {
                int data;
                printf("Enter data: ");
                scanf("%d", &data);

                if (front == -1) front = rear = 0;
                else if (rear == MAX - 1) rear = 0;
                else rear++;

                queue[rear] = data;
                printf("Inserted %d at end of queue\n", data);
            }
            break;
        default:
            printf("Invalid choice");
    }
}

void delete() {
    display();
    printf("1. Delete from beginning\n2. Delete from end\n");
    int choice;
    printf("Enter choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            // Delete from beginning
            if (isEmpty()) printf("Queue is empty!\n");
            else {
                if (front == rear) front = rear = -1;
                else if (front == MAX - 1) front = 0;
                else front++;

                printf("Deleted %d from beginning\n", queue[front]);
                queue[front] = 0;
            }
            break;
        case 2:
            // Delete from end
            if (isEmpty()) printf("Queue is empty!\n");
            else {
                if (front == rear) front = rear = -1;
                else if (rear == 0) rear = MAX - 1;
                else rear--;

                printf("Deleted %d from end\n", queue[rear]);
                queue[rear] = 0;
            }
            break;
        default:
            printf("Invalid choice");
            break;
    }
}

int main() {
    while (1) {
        printf("1. Create queue\n2. Add to queue\n3. Delete from queue\n4. Display queue\n5. Exit\n");
        printf("Enter choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                add();
                break;
            case 3:
                delete();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}