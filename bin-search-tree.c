// created by bhargav on 20/12/20
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} node;

node *newNode(int item) {
    node *temp = (node *) malloc(sizeof(node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d -> ", root->data);
        inorder(root->right);
    }
}

void *insert(node *node, int key) {
    if (node == NULL) return newNode(key);
    if (key < node->data) node->left = insert(node->left, key);
    else node->right = insert(node->right, key);
    return node;
}

node *minValueNode(node *node) {
    struct node *current = node;
    while (current && current->left != NULL) current = current->left;
    return current;
}

node *deleteNode(node *root, int key) {
    if (root == NULL) return root;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node *temp = root->left;
            free(root);
            return temp;
        }

        node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct node *root = NULL;

    while (1) {
        int choice, data;
        printf("1. Add to tree\n2. Inorder traversal\n3. Delete element\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Enter element to be deleted: ");
                scanf("%d", &data);
                deleteNode(root, data);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}