#include <iostream>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;
} NODE;
NODE *start = NULL;
NODE *last = NULL;
void Add_at_Start()
{
    NODE *p = (NODE *)(malloc(sizeof(NODE)));
    cout << "Enter the data that you want to insert-->" << endl;
    cin >> p->data;
    if (start == NULL)
    {
        p->next = NULL;
        start = p;
        last = p;
    }
    else
    {
        p->next = start;
        start = p;
    }
}
void Tranverse()
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
    NODE *p = (NODE *)(malloc(sizeof(NODE)));
    cout << "Enter the data that you want to insert-->" << endl;
    scanf("%d", &p->data);
    if (start == NULL)
    {
        p->next = NULL;
        start = p;
        last = p;
    }
    else
    {
        last->next = p;
        p->next = NULL;
    }
}
void Add_at_Specific_Position()
{
    int a;
    NODE *q = start;
    NODE *p = (NODE *)(malloc(sizeof(NODE)));
    cout << "Enter the position at which the data has to be entered-->\n";
    cin >> a;
    cout << "Enter the data that you want to enter -->\n";
    cin >> p->data;
    for (int i = 1; (i < (a - 1)) && (q != NULL); i++)
    {
        q = q->next;
    }
    p->next = q->next;
    q->next = p;
}
void Delete_at_Start()
{
    NODE *q;
    q = start;
    q = q->next;
    start = q;
}
void Delete_at_End()
{
    NODE *q;
    q = start;
    int a = 0;
    while (q->next != NULL)
    {
        a++;
        q = q->next;
    }
    q = start;
    for (int i = 0; i < a - 1; i++)
    {
        q = q->next;
    }
    q->next = NULL;
}
void Delete_at_Specific_Location()
{
    int a;
    cout << "Enter the location at which the data has to be deleted -->" << endl;
    cin >> a;
    NODE *q = start;
    NODE *q1;
    for (int i = 1; (i < (a - 1) && q != NULL); i++)
    {
        q = q->next;
    }
    q1 = q->next;
    q->next = q1->next;
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
            Tranverse();
            break;
        default:
            cout << "Invalid Choice !!!!!" << endl;
            break;
        }
    } while (choice != 8);

    return 0;
}