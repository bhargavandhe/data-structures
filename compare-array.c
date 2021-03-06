//1. Program to find largest and smallest element in array

#include <stdio.h>

void main (){
    int arr[5], big, small, i;
    
    for (i = 0; i < 5; i++) {
        printf("Enter number %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    big = arr[0];
    small = arr[0];

    for (i = 0; i < 5; i++){
        if (arr[i] > big) big = arr[i];
        if (arr[i] < small) small = arr[i];
    }

    printf("\nLargest element = %d\n", big);
    printf("Smallest element = %d\n", small);
}