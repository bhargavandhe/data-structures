// Created by bhargav on 01/12/20.
#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int queue[MAX], front, rear;

void clrscr() {
    system("clear");
}

void display() {
    clrscr();
    if (front == -1) printf("Queue underflow\n");
    else {
        printf("front = %d, rear = %d\n", front, rear);
        for (int i = 0; i < MAX; i++) printf("%d ", queue[i]);
    }
    printf("\n");
}

void create() {
    clrscr();
    for (int i = 0; i < MAX; i++) queue[i] = 0;
    front = rear = -1;
    printf("Created a queue of SIZE = %d\n", MAX);
}

void insert() {
    clrscr();
    if (rear == MAX - 1 && front == 0) printf("Queue overflow\n");
    else {
        printf("Enter data: ");
        int data;
        scanf("%d", &data);

        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        queue[rear] = data;
        clrscr();
        printf("Added to queue\n");
        display();
    }
}

void delete() {
    clrscr();
    if (front == -1) printf("Queue underflow\n");
    else {
        printf("Deleting %d from queue\n", queue[front]);
        queue[front] = 0;
        if (front == rear) front = rear = -1;
        front == MAX - 1 ? (front = 0) : (front += 1);
        display();
    }
}

void showMenu() {
    while (1) {
        printf("1. Create queue\n2. Insert into queue\n3. Delete from queue\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                insert();
                break;
            case 3:
                delete();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}

int main() {
    showMenu();
    return 0;
}