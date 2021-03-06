#include <stdio.h>
#include <string.h>
#define MAX_LIMIT 20 
struct student {
    char name[10];
    char div;
    int roll;    
};

void main (){
    struct student s1;
    
    printf("Enter name : ");
    fgets(s1.name, MAX_LIMIT, stdin);
    printf("Enter division : ");
    scanf("%c", &s1.div);
    printf("Enter roll no : ");
    scanf("%d", &s1.roll);

    printf("\nHere are the details:\n");
    printf("Name : %s", s1.name);
    printf("Division : %c\n", s1.div);
    printf("Roll no : %d\n", s1.roll);
}