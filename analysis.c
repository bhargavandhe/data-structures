#include <stdio.h>

FILE *file;
char ch;
void main()
{
    int chars = 0, lines = 0, spaces = 0;
    file = fopen("source.txt", "r");
    if (file == NULL)
        printf("Error opening the file!");
    else
    {
        do
        {
            ch = fgetc(file);
            chars += 1;
            if (ch == ' ')
                spaces += 1;
            if (ch == '\n')
                lines += 1;
            printf("%c", ch);

        } while (ch != EOF);
        printf("\n\nNo. of chars: %d", chars);
        printf("\nNo. of lines: %d", lines + 1);
        printf("\nNo. of spaces: %d\n", spaces);
    }
}