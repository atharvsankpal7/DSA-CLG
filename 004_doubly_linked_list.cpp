#include <iostream>
using namespace std;
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
    cout << "Enter the data -->";
    cin >> p->data;
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
        cout << "The linked list is empty";
    }
    else
    {
        NODE *q;
        q = start;
        cout << "The linked list is as follows:\n";
        while (q != NULL)
        {
            cout << q->data << endl;
            q = q->next;
        }
    }
}
void Add_at_End()
{
    NODE *p = (NODE *)malloc(sizeof(NODE));
    cout << "Enter the data -->";
    cin >> p->data;
    if (start == NULL)
    {
        p->next = NULL;
        p->prev = NULL;
        start = p;
    }
    else
    {
        NODE *q;
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
    cout << "Enter the data -->";
    cin >> p->data;
    cout << "Enter the location -->";
    cin >> a;
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
        cout << "The linked list is empty!!\n";
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
        cout << "The linked list is empty!!\n";
    }
    else
    {
        NODE *q = start;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = NULL;
    }
}

void Delete_at_Specific_Location()
{
}
int main()
{
    int choice;
    cout << "Enter the operation you want to perform on the linked list" << endl;
    do
    {
        cout << "1.Add a node at start\n2.Add a node at end\n3.Add a node a specific location\n4.Delete a node present at start\n5.Delete a node present at end\n6.Delete a node a specific location\n7.Traverese\n8.Exit the program" << endl;
        cin >> choice;
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
            cout << "Invalid Choice !!!!!" << endl;
            break;
        }
    } while (choice != 8);

    return 0;
}