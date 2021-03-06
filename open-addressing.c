#include <stdio.h>
#include <stdlib.h>
#define LEN 10

int array[LEN];
void showMenu();

int isArrayEmpty()
{
    /* Returns 0 if array is full
       Returns 1 if array has empty space left
    */
    int flag = 0;
    for (int i = 0; i < LEN; i++)
    {
        if (array[i] == 0)
            flag = 1;
    }
    return flag;
}
int getIndexof(int e)
{
    /* Returns -1 if element is not found
       Returns a positive integer if element is found
    */
    int flag = -1;
    int index = e % 10;
    if (array[index] == e)
        flag = index;
    else
    {
        for (int i = 0; i < LEN; i++)
        {
            if (array[index + 1] == e)
            {
                flag = index + 1;
                break;
            }
            else
                index = (index + 1) % 10;
        }
    }
    return flag;
}
void insert()
{
    int e, index;
    if (isArrayEmpty()) // Insert elements only if there is free space
    {
        printf("Enter value to be inserted: ");
        scanf("%d", &e);
        if (getIndexof(e) == -1) // Inserting only unique elements
        {
            index = e % 10;
            if (array[index] == 0)
            {
                array[index] = e;
                printf("Successfully inserted %d at %d index\n", e, index);
            }
            else
            {
                printf("Collision occurred, resolving using open-addressing....");
                while (1)
                {
                    if (array[index + 1] == 0)
                    {
                        array[index + 1] = e;
                        printf("\nSuccesfully inserted %d at %d index\n", e, index + 1);
                        break;
                    }
                    else
                        index = (index + 1) % 10;
                }
            }
        }
        else
            printf("Element already present in array!\n");
    }
    else
        printf("Array is full, please delete some elements!\n");
    showMenu();
}
void delete ()
{
    int e, index;
    printf("Enter value to be deleted: ");
    scanf("%d", &e);
    index = getIndexof(e);
    if (index >= 0)
    {
        array[index] = 0;
        printf("Successfully deleted %d from array.\n", e);
    }
    else
        printf("Element not found!\n");
}
void search()
{
    int e, index = -1;
    printf("Enter element to be searched: ");
    scanf("%d", &e);
    index = getIndexof(e);
    if (index >= 0)
        printf("Found %d at %d index\n", e, index);
    else
        printf("Element not found!\n");
}
void display()
{
    for (int i = 0; i < LEN; i++)
        printf("array[%d] = %d\n", i, array[i]);
}
void showMenu()
{
    int choice;
    printf("1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        insert();
        break;
    case 2:
        delete ();
        break;
    case 3:
        search();
        break;
    case 4:
        display();
        break;
    case 5:
        printf("Exiting ...\n");
        exit(0);
    default:
        printf("Invalid choice, try again!\n");
        showMenu();
        break;
    }
    showMenu();
}

void main()
{
    showMenu();
}