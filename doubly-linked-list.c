#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
} node;
node *head;

void insertion_beginning() {
    node *ptr;
    int item;
    ptr = (node *) malloc(sizeof(node));
    if (ptr == NULL) {
        printf("\nOVERFLOW");
    } else {
        printf("\nEnter Item value->");
        scanf("%d", &item);
        if (head == NULL) {
            ptr->next = NULL;
            ptr->prev = NULL;
            ptr->data = item;
            head = ptr;
        } else {
            ptr->data = item;
            ptr->prev = NULL;
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
        }
        printf("\nNode inserted successfully\n");
    }
}

void insertion_last() {
    node *ptr, *temp;
    int item;
    ptr = (node *) malloc(sizeof(node));
    if (ptr == NULL) printf("\nOVERFLOW");
    else {
        printf("\nEnter Item value->");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL) {
            ptr->next = NULL;
            ptr->prev = NULL;
            head = ptr;
        } else {
            temp = head;
            while (temp->next != NULL) temp = temp->next;
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = NULL;
        }
    }
    printf("\nNode inserted successfully\n");
}

void insertion_specified() {
    node *ptr, *temp;
    int item, loc, i;
    ptr = (node *) malloc(sizeof(node));
    if (ptr == NULL) printf("\n OVERFLOW");
    else {
        temp = head;
        printf("Enter the location");
        scanf("%d", &loc);
        for (i = 0; i < loc; i++) {
            temp = temp->next;
            if (temp == NULL) {
                printf("\n There are less than %d elements", loc);
                return;
            }
        }
        printf("Enter value");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = temp->next;
        ptr->prev = temp;
        temp->next = ptr;
        temp->next->prev = ptr;
        printf("\nNode inserted successfully\n");
    }
}

void deletion_beginning() {
    node *ptr;
    if (head == NULL) printf("\n UNDERFLOW");
    else if (head->next == NULL) {
        head = NULL;
        free(head);
        printf("\nNode deleted\n");
    } else {
        ptr = head;
        head = head->next;
        head->prev = NULL;
        free(ptr);
        printf("\nNode deleted\n");
    }
}

void deletion_last() {
    node *ptr;
    if (head == NULL) printf("\n UNDERFLOW");
    else if (head->next == NULL) {
        head = NULL;
        free(head);
        printf("\nNode deleted\n");
    } else {
        ptr = head;
        if (ptr->next != NULL) ptr = ptr->next;
        ptr->prev->next = NULL;
        free(ptr);
        printf("\nNode deleted\n");
    }
}

void deletion_specified() {
    node *ptr, *temp;
    int val;
    printf("\n Enter the data after which the node is to be deleted : ");
    scanf("%d", &val);
    ptr = head;
    while (ptr->data != val) ptr = ptr->next;
    if (ptr->next == NULL) printf("\nCan't delete\n");
    else if (ptr->next->next == NULL) ptr->next = NULL;
    else {
        temp = ptr->next;
        ptr->next = temp->next;
        temp->next->prev = ptr;
        free(temp);
        printf("\nNode deleted\n");
    }
}

void insert() {
    int choice;
    do {
        printf("\n--------------------------------------\n");
        printf("\n 1.Insert at the beginning: ");
        printf("\n 2.Insert at specified position: ");
        printf("\n 3.Insert at the end: ");
        printf("\n 4.Exit from insert: ");
        printf("\n--------------------------------------\n");
        printf("\nEnter Your Choice-> ");
        scanf("%d", &choice);
        printf("\n--------------------------------------\n");
        switch (choice) {
            case 1:
                insertion_beginning();
                break;
            case 2:
                insertion_specified();
                break;
            case 3:
                insertion_last();
                break;
            case 4:
                break;
            default:
                printf("Wrong Choice");
        }
    } while (choice != 4);
}

void delete() {
    int choice;
    do {
        printf("\n--------------------------------------\n");
        printf("\n 1.Delete at the beginning: ");
        printf("\n 2.Delete at specified position: ");
        printf("\n 3.Delete at the end: ");
        printf("\n 4.Exit from insert: ");
        printf("\n--------------------------------------\n");
        printf("\nEnter Your Choice-> ");
        scanf("%d", &choice);
        printf("\n--------------------------------------\n");
        switch (choice) {
            case 1:
                deletion_beginning();
                break;
            case 2:
                deletion_specified();
                break;
            case 3:
                deletion_last();
                break;
            case 4:
                break;
            default:
                printf("Wrong Choice");
        }
    } while (choice != 4);
}

void display() {
    node *ptr;
    printf("\n Elements present in the list are...\n");
    ptr = head;
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

void search() {
    node *ptr;
    int item, i = 0, flag;
    ptr = head;
    if (ptr == NULL) printf("\nEmpty List\n");
    else {
        printf("\nEnter item which you want to search?\n");
        scanf("%d", &item);
        while (ptr != NULL) {
            if (ptr->data == item) {
                printf("\nItem found at location %d ", i + 1);
                flag = 0;
                break;
            } else flag = 1;
            i++;
            ptr = ptr->next;
        }
        if (flag == 1) printf("\nItem not found\n");
    }
}

int main() {
    int choice = 0;
    while (choice != 9) {
        printf("\n*******MENU*******\n");
        printf("\n 1.Insert \n");
        printf("\n 2.Delete \n");
        printf("\n 3.Search \n");
        printf("\n 4.Display \n");
        printf("\n 5.Exit \n");
        printf("\n--------------------------------------\n");
        printf("Enter your choice-> ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                search();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Please enter valid choice\n");
        }
    }
}