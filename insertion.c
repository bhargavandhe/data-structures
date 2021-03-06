#include <stdio.h>

void main()
{
    int array[] = {4, 6, 7, 2, 1, 3, 8, 9, 0, 5};
    int temp;
    printf("Before sort: \n");
    for (int i = 0; i < sizeof array; i++)
        printf("%d ", array[i]);

    printf("Sorting ....");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (array[j] > array[i])
            {
                /* Code */
            }
        }
    }
    for (int i = 0; i < sizeof array; i++)
        printf("%d ", array[i]);
}