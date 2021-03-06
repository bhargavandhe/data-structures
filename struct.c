#include <stdio.h>

struct student{
    char div;
    int roll;
};

void main (){
    struct student s[3];
    printf("%lu\n", sizeof(s));

    for (int i = 0; i < 3; i++){
        printf("Enter division: ");
        scanf("%s", &s[i].div);
        printf("Enter roll-no: ");
        scanf("%d", &s[i].roll);
    }
}