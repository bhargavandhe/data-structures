#include <stdio.h>
#include <math.h>
int array[] = {44, 66, 78, 54, 94, 12, 84, 35, 22};
int bin[sizeof array + 1];

void main()
{
    int index;
    for (int i = 1; i < 3; i++)
    {
        for (int j = 0; j < sizeof array; j++)
        {
            index = array[j] % (int)pow(10, i);
        }
    }
}