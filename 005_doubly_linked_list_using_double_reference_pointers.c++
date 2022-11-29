#include <iostream>
using namespace std;
int counter = 0;
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node NODE;
NODE *start = NULL;
NODE *last = NULL;
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
        counter++;
        last = p;
    }
    else
    {
        p->next = start;
        p->prev = NULL;
        start = p;
        counter++;
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
        last = p;
        counter++;
    }
    else
    {
        p->next = NULL;
        last->next = p;
        p->prev = last;
        last = p;
        counter++;
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
            counter++;
            last = p;
        }
        else
        {
            p->next = start;
            p->prev = NULL;
            start = p;
            counter++;
        }
    }
    else if (a > counter)
    {
        cout << "The location does not exist\n";
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
        counter++;
    }
}
void Delete_at_Start()
{
    if (start == NULL)
    {
        cout << "The linked list is empty!!\n";
    }
    else if (counter == 1)
    {
        NODE *q = start;
        start = NULL;
        last = NULL;
        free(q);
        counter--;
    }
    else
    {
        NODE *q = start;
        start->next->prev = NULL;
        start = start->next;
        free(q);
        counter--;
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
        NODE *q = last;
        last->prev->next = NULL;
        last = last->prev;
        free(q);
        counter--;
    }
}
void Delete_at_Specific_Location()
{
    int a;
    cout << "Enter the location -->" << endl;
    cin >> a;
    if (a == 1)
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
            counter--;
        }
    }
    else if (a == counter)
    {
        if (start == NULL)
        {
            cout << "The linked list is empty!!\n";
        }
        else
        {
            NODE *q = last;
            last->prev->next = NULL;
            last = last->prev;
            free(q);
            counter--;
        }
    }
    else if (a > counter)
    {
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\nThe given location does not exist\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
    }
    else
    {
        NODE *q = start;
        for (int i = 1; i < a; i++)
        {
            q = q->next;
        }
        if (q->next == NULL)
        {
            NODE *q = last;
            last->prev->next = NULL;
            last = last->prev;
            free(q);
            counter--;
        }
        else
        {
            q->prev->next = q->next;
            q->next->prev = q->prev;
            free(q);
        }
    }
}
int main()
{
    int choice;
    cout << "Enter the operation you want to perform on the linked list" << endl;
    do
    {
        cout << "1.Add a node at start\n2.Add a node at end\n3.Add a node a specific location\n4.Delete a node present at start\n5.Delete a node present at end\n6.Delete a node a specific location\n7.Tranverese\n8.Exit the program" << endl;
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