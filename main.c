#include<stdio.h>
#include<stdlib.h>

struct CQ {
    int data;
    struct CQ *next;
};
struct CQ *Front = NULL, *Rear = NULL, *q, *p;
int i = 0;

void Enqueue();

void Dequeue();

void Display();

void main() {
    int ch, n;
    do {
        printf("\nEnter your choice:\n");
        printf("\n1.Create CQ\n");
        printf("\n2.Enqueue\n");
        printf("\n3.Dequeue\n");
        printf("\n4.Display\n");
        printf("\n5.Exit\n");
        scanf("\n%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter the Size of Circular Queue:\n");
                scanf("%d", &n);
                printf("\nThe CQ is successfully Created of size %d\n", n);
                break;
            case 2:
                if (i != n) {
                    Enqueue();
                    i++;
                } else
                    printf("\nCQ is FULL!!!\n");
                break;
            case 3:
                Dequeue();
                break;
            case 4:
                Display();
                break;
            case 5:
                exit(1);
                break;
            default:
                printf("\n Invalid Input\n");
        }
    } while (ch != 5);
}

void Enqueue() {
    struct CQ *nn;
    nn = (struct CQ *) malloc(sizeof(struct CQ));
    printf("Enter Element to be added in CQ:\n");
    scanf("%d", &nn->data);
    if (Front == NULL) {
        Front = nn;
        Rear = nn;
    } else {
        Rear->next = nn;
        Rear = nn;
    }
    Rear->next = Front;
    printf("%d is successfully added\n", nn->data);
}

void Dequeue() {
    struct CQ *temp;
    int x;
    if (Front == NULL) {
        printf("CQ is empty\n");
    }
    temp = Front;
    x = Front->data;
    if (Front == Rear) {
        Front = NULL;
        Rear = NULL;
    } else {
        Front = Front->next;
        Rear->next = Front;
    }
    free(temp);
    printf("%d is deleted\n", x);
    i--;
}

void Display() {
    q = Front;
    if (Front == NULL && Rear == NULL) {
        printf("\nCQ is Empty\n");
    } else {
        do {
            printf("%d\t", q->data);
            q = q->next;
        } while (q != Front);
    }
}