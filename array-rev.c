//3. Program to print array in reverse and copy it to another array

#include <stdio.h>

void main (){
    int a[3], b[3], i, j=2;

    for (i = 0; i < 3; i++) {
        printf("Enter number %d: ", i+1);
        scanf("%d", &a[i]);
        b[j--] = a[i];
    }
    printf("\nArray in reverse :\n");
    for (i = 0; i < 3; i++) printf("%d\n", b[i]);
}