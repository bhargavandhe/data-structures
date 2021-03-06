#include <stdio.h>

FILE *file;

void main()
{
    char text[30];
    printf("Enter text: ");
    fgets(text, 30, stdin);

    file = fopen("target.txt", "w");
    fputs(text, file);
    printf("Successfully wrote data to file!\n");
}