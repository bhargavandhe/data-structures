#include <stdio.h>
#define LEN 5

int array[LEN];
void sort()
{
}

void main()
{
    printf("Enter elements in array: \n");
    for (int i = 0; i < LEN; i++)
    {
        printf("%d) ", i);
        scanf("%d", &array[i]);
    }
    sort();
}