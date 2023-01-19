/*
Name- Atharv Santosh Sankpal
URN - 21031040
Practical NO - 2
Practical Title - Singly linked list
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} NODE;
NODE *start1 = NULL, *start2 = NULL;
void InsertAtStart(NODE **start)
{
    NODE *p = (NODE *)malloc(sizeof(NODE));
    printf("Enter the data -->\n");
    scanf("%d", &p->data);
    if (*start == NULL)
    {
        *start = p;
        p->next = NULL;
    }
    else
    {
        p->next = *start;
        *start = p;
    }
}
void Display(NODE **start)
{
    NODE *p = *start;
    if (p == NULL)
    {
        printf("The linked list is empty\n");
    }
    else
    {
        printf("The linked list is as follows -->\n");
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}
void add()
{
    NODE *p1 = start1, *p2 = start2, *start3 = start1, *p = start3;
    while (start2 != NULL)
    {
        start1 = start1->next;
        p->next = start2;
        p = p->next;
        start2 = start2->next;
        p->next = start1;
        p = p->next;
    }
    printf("The linked list after merging of new linked list is :");
    NODE *p3 = start3;
    while (p3 != NULL)
    {
        printf("%d ", p3->data);
        p3 = p3->next;
    }
    printf("\n");
}
int main()
{
    int n;
    printf("Welcome to the program\n");

    do
    {
        printf("1. Insert at start LL1\n2. Insert at start LL2 \n3. Display the linked list 1\n4. Display the linked list 2\n5. Add the linked lists\n6. EXIT!!\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            InsertAtStart(&start1);
            break;

        case 2:
            InsertAtStart(&start2);
            break;
        case 3:
            Display(&start1);
            break;
        case 4:
            Display(&start2);
            break;
        case 5:
            add();
            break;
        case 6:
            printf("Exiting the program\n");
            break;
        default:
            printf("Invalid Option!!!\n");
            break;
        }

    } while (n != 7);
}