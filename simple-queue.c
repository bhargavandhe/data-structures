#include <stdio.h>
#include <stdlib.h>
// Created by bhargav on 23/11/20.

#define MAX 10
int queue[MAX];
int front, rear;

void create() {
    for (int i = 0; i < MAX; i++) queue[i] = 0;
    front = -1,
            rear = -1;
    printf("Created a queue of SIZE = %d\n", MAX);
}

void enqueue() {
    printf("front = %d, rear = %d\n", front, rear);
    if (front != MAX - 1 && rear != MAX - 1) {
        printf("Enter data to be inserted: ");
        int data;
        scanf("%d", &data);
        if (front == -1 && rear == -1) {
            queue[0] = data;
            front++, rear++;
        } else queue[++rear] = data;
        
        printf("Added to queue\n");
        display();
    } else printf("Queue overflow!\n");
}

int isEmpty() {
    for (int i = 0; i < MAX; ++i)
        if (queue[i] != 0) return 0;
    return 1;
}

void dequeue() {
    printf("front = %d, rear = %d\n", front, rear);
    if (!isEmpty()) {
        queue[front++] = 0;
        
        printf("Removed from Queue\n");
        display();
    } else printf("Queue underflow\n");
}

void display() {
    for (int i = 0; i < MAX; ++i) printf("%d ", queue[i]);
    
    printf("\n");
}

int main() {
    while (1) {
        int choice;
        printf("1. Create QUEUE\n2. ENQUEUE\n3. DEQUEUE\n4. Maximum(Q)\n5. Display\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                enqueue();
                break;
            case 3:
                dequeue();
                break;
            case 4:
                printf("Maximum size: %d\n", MAX);
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}