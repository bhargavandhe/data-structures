#include <stdio.h>

FILE *source, *target;
char ch;
void main()
{
    source = fopen("source.txt", "r");
    target = fopen("target.txt", "w");
    if (source == NULL)
        printf("Cannot open file!");
    else
        do
        {
            ch = fgetc(source);
            if (ch == EOF)
                break;
            else
                fputc(ch, target);
        } while (ch != EOF);
    fclose(source);
    fclose(target);
    printf("Content successfully copied!\n");
}