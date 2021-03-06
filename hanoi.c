#include <stdio.h>

// Created by bhargav on 17/11/20.
void move(int size, char *from, char *to, char *aux) {
    if (size == 1) {
        printf("Moving disk %d from %s to %s\n", size, from, to);
        return;
    }
    move(size - 1, from, aux, to);
    printf("Moved disk %d from %s to %s\n", size, from, to);
    move(size - 1, aux, to, from);
}

int main() {
    printf("Enter no. of disks: ");
    int size = 1;
    scanf("%d", &size);
    printf("Created an SOURCE TOWER with %d disks\n", size);
    move(size, "SOURCE TOWER", "DESTINATION TOWER", "AUXILIARY TOWER");
    return 0;
}