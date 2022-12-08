/*
Name- Atharv Santosh Sankpal
URN - 21031040
Practical NO - 2
Practical Title - Doubly linked list
*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node NODE;
NODE *start = NULL;
void Add_at_Start()
{
    NODE *p = (NODE *)malloc(sizeof(NODE));
    printf("Enter the data -->\n");
    scanf("%d", &p->data);
    if (start == NULL)
    {
        p->next = NULL;
        p->prev = NULL;
        start = p;
    }
    else
    {
        p->next = start;
        p->prev = NULL;
        start = p;
    }
}
void Traverse()
{
    if (start == NULL)
    {
        printf("The linked list is empty!!!\n");
    }
    else
    {
        NODE *q = start;
        printf("The linked list is as follows\n");
        while (q != NULL)
        {
            printf("%d ", q->data);
            q = q->next;
        }
        printf("\n");
    }
}
void Add_at_End()
{
    NODE *p = (NODE *)malloc(sizeof(NODE));
    printf("Enter the data -->\n");
    scanf("%d", &p->data);
    if (start == NULL)
    {
        p->next = NULL;
        p->prev = NULL;
        start = p;
    }
    else
    {
        NODE *q = start;
        while (q->next != NULL)
        {
            q = q->next;
        }
        p->next = NULL;
        p->prev = q;
        q->next = p;
    }
}
void Add_at_Specific_Position()
{
    int a;
    NODE *p = (NODE *)malloc(sizeof(NODE));
    printf("Enter the data -->\n");
    scanf("%d", &p->data);
    printf("Enter the location\n");
    scanf("%d", &a);
    NODE *q = start;

    if (a == 1)
    {
        if (start == NULL)
        {
            p->next = NULL;
            p->prev = NULL;
            start = p;
        }
        else
        {
            p->next = start;
            p->prev = NULL;
            start = p;
        }
    }
    else
    {
        for (int i = 1; i < a - 1 && q != NULL; i++)
        {
            q = q->next;
        }
        p->next = q->next;
        p->prev = q;
        q->next = p;
    }
}
void Delete_at_Start()
{
    if (start == NULL)
    {
        printf("The linked list is empty\n");
    }
    else
    {
        NODE *q = start;
        start->next->prev = NULL;
        start = start->next;
        free(q);
    }
}

void Delete_at_End()
{
    if (start == NULL)
    {
        printf("The linked list is empty\n");
    }
    else
    {
        NODE *q = start;
        while (q->next->next != NULL)
        {
            q = q->next;
        }
        q->next = NULL;
    }
}

void Delete_at_Specific_Location()
{
    if (start == NULL)
    {
        printf("The linked list is empty\n");
    }
    else
    {
        int a;
        printf("Enter the location at which the data has to be deleted-->\n");
        scanf("%d", &a);
        NODE *q = start;
        NODE *q1;
        for (int i = 1; (i < (a - 1) && q != NULL); i++)
        {
            q = q->next;
        }
        q1 = q->next;
        q->next = q1->next;
    }
}
int main()
{
    int choice;
    printf("Enter the operation you want to perform on the linked list\n");
    do
    {
        printf("1.Add a node at start\n2.Add a node at end\n3.Add a node a "
               "specific location\n4.Delete a node present at start\n5.Delete a "
               "node present at end\n6.Delete a node a specific "
               "location\n7.Traverese\n8.Exit the program\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Add_at_Start();
            break;
        case 2:
            Add_at_End();
            break;
        case 3:
            Add_at_Specific_Position();
            break;
        case 4:
            Delete_at_Start();
            break;
        case 5:
            Delete_at_End();
            break;
        case 6:
            Delete_at_Specific_Location();
            break;
        case 7:
            Traverse();
            break;
        default:
            printf("Invalid Choice !!!!!\n");
            break;
        }
    } while (choice != 8);

    return 0;
}