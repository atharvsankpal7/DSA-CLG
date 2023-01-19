/*
Name- Atharv Santosh Sankpal
URN - 21031040
Practical NO - 5
Practical Title - Deleting a duplicate node
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} NODE;
NODE *start = NULL;
void InsertAtStart()
{
    NODE *p = (NODE *)malloc(sizeof(NODE));
    printf("Enter the data -->\n");
    scanf("%d", &p->data);
    if (start == NULL)
    {
        start = p;
        p->next = NULL;
    }
    else
    {
        p->next = start;
        start = p;
    }
}
void InsertAtEnd()
{
    NODE *p = (NODE *)malloc(sizeof(NODE));
    printf("Enter the data -->\n");
    scanf("%d", &p->data);
    if (start == NULL)
    {
        start = p;
        p->next = NULL;
    }
    else
    {
        NODE *q = start;
        while (q->next != NULL)
        {
            q = q->next;
        }
        p->next = NULL;
        q->next = p;
    }
}
void InsertAtPosition()
{
    NODE *p = (NODE *)malloc(sizeof(NODE));
    printf("Enter the data -->\n");
    scanf("%d", &p->data);
    int n;
    printf("Enter the location\n");
    scanf("%d", &n);
    NODE *q = start;
    for (int i = 0; i < n - 2 && q != NULL; i++)
    {
        q = q->next;
    }
    if (q == NULL)
    {
        printf("The position does not exist\n");
    }
    else
    {
        p->next = q->next;
        q->next = p;
    }
}
void DeleteAtStart()
{
    if (start == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        NODE *p = start;
        start = start->next;
        free(p);
    }
}
void DeleteAtEnd()
{
    if (start == NULL)
    {

        printf("The linked list is empty\n");
    }
    else
    {
        NODE *p = start;
        NODE *q;
        while (p->next->next != NULL)
        {

            p = p->next;
        }
        p->next = NULL;
        free(p->next);
    }
}
void DeleteAtPosition()
{
    int n;
    printf("Enter the location\n");
    scanf("%d", &n);
    NODE *p = start;
    NODE *q;
    for (int i = 0; i < n - 2 && p != NULL; i++)
    {
        p = p->next;
    }
    if (p == NULL)
    {
        printf("The position does not exist\n");
    }
    else
    {
        q = p->next;
        p->next = p->next->next;
        free(q);
    }
}
void Display()
{
    NODE *p = start;
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
void Reverse_Linked_List()
{
    NODE *p = NULL, *q, *r = start;
    while (r != NULL)
    {
        q = r->next;
        r->next = p;
        p = r;
        r = q;
    }
    start = p;
}
int main()
{
    int n;
    printf("Welcome to the program\n");

    do
    {
        printf("1. Insert at start\n2. Insert at end\n3. Insert at Specific "
               "location\n4. Delete at start\n5. Delete at end\n6. Delete at given "
               "location\n7. Display the linked list\n8.Reverse the linked list\n9. EXIT!!\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            InsertAtStart();
            break;

        case 2:
            InsertAtEnd();
            break;
        case 3:
            InsertAtPosition();
            break;
        case 4:
            DeleteAtStart();
            break;
        case 5:
            DeleteAtEnd();
            break;
        case 6:
            DeleteAtPosition();
            break;
        case 7:
            Display();
            break;
        case 8:
            Reverse_Linked_List();
            break;
        case 9:
            printf("Exiting the program\n");
            break;
        default:
            printf("Invalid Option!!!\n");
            break;
        }

    } while (n != 9);
}