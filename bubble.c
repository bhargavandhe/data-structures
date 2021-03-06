#include <stdio.h>

void sort(int LEN)
{
    int array[LEN];
    for (int i = 0; i < LEN; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("\nBefore sorting: \n");
    for (int i = 0; i < LEN; i++)
        printf("%d ", array[i]);
    printf("\n");

    for (int i = 0; i < LEN - 1; i++)
    {
        for (int j = 0; j < LEN - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    printf("\nAfter sorting: \n");
    for (int i = 0; i < LEN; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void main()
{
    int lim;
    printf("Enter no of elements: ");
    scanf("%d", &lim);
    sort(lim);
}