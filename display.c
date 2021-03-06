#include <stdio.h>

FILE *file;
char ch;
void main()
{
    file = fopen("source.txt", "r");
    if (file == NULL)
        printf("Error in opening the file!");
    else
    {
        do
        {
            ch = fgetc(file);
            printf("%c", ch);

        } while (ch != EOF);
        printf("\n");
    }
}