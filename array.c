//2. Program to find even, odd, positive and negative elements in an array

#include <stdio.h>

void main(){
    int pos, neg, even, odd, i;
    int arr[5];
    pos = 0;
    neg = 0;
    even = 0;
    odd = 0;
    
    for (i = 0; i < 5; i++) {
        printf("Enter number %d: ", i+1);
        scanf("%d", &arr[i]);

        if (arr[i] >= 0) pos++;
        else neg++;

        if (arr[i] % 2 == 0) even++;
        else odd++;
    }    

    printf("\nEven Count = %d", even);
    printf("\nOdd Count = %d", odd);
    printf("\nPositive Count = %d", pos);
    printf("\nNegative Count = %d\n", neg);
}