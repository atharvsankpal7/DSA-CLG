#include <stdio.h>

#include <stdlib.h>

#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
NODE *start = NULL, *p, *q;
void create_at_start()
{
    p = (NODE *)malloc(sizeof(NODE));
    printf("Enter the data --> ");
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
void create_at_end()
{
    p = (NODE *)malloc(sizeof(NODE));
    printf("Enter the data --> ");
    scanf("%d", &p->data);
    if (start == NULL)
    {
        start = p;
        p->next = NULL;
    }
    else
    {
        q = start;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
        p->next = NULL;
    }
}
void traverse()
{
    if (start == NULL)
    {
        printf("The Linked List is empty\n");
    }
    else
    {
        printf("The linked list is -->\t");
        p = start;
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}
void delete_at_start()
{
    if (start == NULL)
    {
        printf("The Linked list is empty\n");
    }
    else
    {
        start = start->next;
    }
}
void delete_at_end()
{
    if (start == NULL)
    {
        printf("The linked list is empty\n");
    }
    else
    {
        p = start;
        while (p->next->next != NULL)
        {
            p = p->next;
        }
        p->next = NULL;
    }
}
void delete_at_given_location()
{
    int loc;
    printf("Enter the location where you want to delete the location\n");
    scanf("%d", &loc);
    if (loc == 1)
    {
        delete_at_end();
    }
    else
    {
        p = start;
        for (int i = 1; i < loc - 1; i++)
        {
            p = p->next;
        }
        if (p->next->next = NULL)
        {
            p->next = NULL;
        }
        else if (p->next == NULL)
        {
            delete_at_end();
        }
        else
        {
            p->next = p->next->next;
        }
    }
}
void create_at_given_location()
{
    int loc;
    printf("Enter the location where you want to insert the location \n");
    scanf("%d", &loc);
    if (loc == 1)
    {
        create_at_start();
    }
    else
    {
        p = start;
        q = (NODE *)malloc(sizeof(NODE));
        printf("Enter the data -->");
        scanf("%d", &q->data);
        for (int i = 0; i < loc - 1; i++)
        {
            p = p->next;
        }
        if (p->next == NULL)
        {
            create_at_start();
        }
        else
        {
            q->next = p->next;
            p->next = q;
        }
    }
}
void delete_duplicates()
{
    if (start == NULL)
    {
        printf("The linked list is empty\n");
    }
    else
    {
        p = start;
        while (p != NULL)
        {
            q = p;
            while (q->next != NULL)
            {
                if (p->data == q->next->data)
                {
                    q->next = q->next->next;
                }
                else
                {
                    q = q->next;
                }
            }
            p = p->next;
        }
    }
}
bool check_palindrome()
{
    int arr[1000], i = 0;
    if (start == NULL)
    {
        printf("The linked list is empty\n");
    }
    else
    {

        p = start;
        while (p != NULL)
        {
            arr[i] = p->data;
            i++;
            p = p->next;
        }
    }
    for (int j = 0; j < (i / 2); j++)
    {
        if (arr[j] != arr[i - j - 1])
        {
            return false;
        }
    }
    return true;
}
void reverse_even()
{
    if (start == NULL)
    {
        printf("The linked list is empty\n");
    }
    else
    {
        p = start;
        int counter = 1;
        NODE *start_new = NULL, *start3, *k;
        while (p->next != NULL && p != NULL)
        {
            if (start_new == NULL)
            {
                start_new = p->next;
                p->next = p->next->next;
                start_new->next = NULL;
            }
            else
            {
                k = p->next;
                p->next = p->next->next;
                k->next = start_new;
                start_new = k;
            }
            p = p->next;
        }
        p = start;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = start_new;
    }
}
/*
 // For merging of the 2 sorted linked list.
 void merge_helper_create_at_end(NODE **start_merge_helper)
 {
     NODE *q_merge_helper;
     NODE *p_merge_helper = (NODE *)malloc(sizeof(NODE));
     printf("Enter the data --> ");
     scanf("%d", &p_merge_helper->data);
     if (*start_merge_helper == NULL)
     {
         *start_merge_helper = p_merge_helper;
         p_merge_helper->next = NULL;
         q_merge_helper = p_merge_helper;
     }
     else
     {
         q_merge_helper->next = p_merge_helper;
         p_merge_helper->next = NULL;
         q_merge_helper = p_merge_helper;
     }
 }
 void merge(NODE *start1, NODE *start2)
 {
     NODE *start_new_merge = NULL;
     NODE *a = start1, *b = start2, *c = start_new_merge;
     while (a != NULL && b != NULL)
     {
         if (a->data < b->data)
         {
             start1 = start1->next;
             if (start_new_merge == NULL)
             {
                 start_new_merge = a;
                 a->next = NULL;
                 c = a;
             }
             else
             {
                 c->next = a;
                 a->next = NULL;
                 c = a;
             }
             a = start1;
         }
         else
         {
             start2 = start2->next;
             if (start_new_merge == NULL)
             {
                 start_new_merge = b;
                 b->next = NULL;
                 c = b;
             }
             else
             {
                 c->next = b;
                 b->next = NULL;
                 c = b;
             }
             b = start2;
         }
     }
     c = start_new_merge;
     printf("After merging the linked list looks like this --> \n");
     while (c != NULL)
     {
         printf("%d ", c->data);
         c = c->next;
     }
     printf("\n");
 }
 void merge_driver()
 {
     int ch;
     NODE *start1, *start2;
     do
     {
         printf("1.Create at Linked list 1\n2.Create at Linked list 2\n3.Merge the Linked list\n");
         scanf("%d", &ch);
         switch (ch)
         {
         case 1:
             merge_helper_create_at_end(&start1);
             break;
         case 2:
             merge_helper_create_at_end(&start2);
             break;
         case 3:
             merge(start1, start2);
         default:
             break;
         }

     } while (ch != 0);
 }
 */
void reverse_linked_list()
{
    NODE *p = start, *q, *r = NULL;
    while (p != NULL)
    {
        q = p->next;
        p->next = r;
        r = p;
        p = q;
    }
    start = r;
}

void sort_linked_list()
{
    p = start;
    while (p != NULL && p->next != NULL)
    {
        q = p->next;
        while (q != NULL)
        {
            if (p->data > q->data)
            {
                int temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
}
void insert_in_sorted_order()
{
    NODE *new_node = (NODE *)malloc(sizeof(NODE));
    printf("Enter the data that you want to insert -->\n");
    scanf("%d", &new_node->data);
    if (start == NULL)
    {
        create_at_start();
    }
    else
    {
        p = start;
        while (p->next != NULL)
        {
            if (new_node->data > p->next->data)
            {
                p = p->next;
            }
            else
            {
                if (start == p)
                {
                    new_node->next = start;
                    start = new_node;
                }
                else
                {
                    new_node->next = p->next;
                    p->next = new_node;
                }
                break;
            }
        }
        if (p->next == NULL)
        {
            new_node->next = NULL;
            p->next = new_node;
        }
    }
}
void last_divisible_node()
{
    p = start;
    int counter = 0, key, key_element;
    printf("Enter the key element\n");
    scanf("%d", &key);
    while (p != NULL)
    {
        counter++;
        p = p->next;
    }
    p = start;
    while (p->next != NULL)
    {
        if (counter % key == 0)
        {
            key_element = p->data;
        }
        counter--;
        p = p->next;
    }
    printf("The last divisible node is %d\n", key_element);
}
int main()
{
    int ch;
    printf("Enter the choice\n");
    do
    {
        printf("1.Create at start\n2.Create at End\n3.Create at Given Location\n4.Delete at start\n5.Delete at end\n6.Delete at given location\n7.Traverse\n8.Delete Duplicates\n9.Check Palindrome\n10.Reverse Even nodes\n\n12.Reverse the linked list\n13.Sort the linked list\n14.Insert the element in sorted way\n15.Find the last divisible node\n0.EXIT\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            printf("The program has been terminated\n");
            break;
        case 1:
            create_at_start();
            break;
        case 2:
            create_at_end();
            break;
        case 3:
            create_at_given_location();
            break;
        case 4:
            delete_at_start();
            break;
        case 5:
            delete_at_end();
            break;
        case 6:
            delete_at_given_location();
            break;
        case 7:
            traverse();
            break;
        case 8:
            delete_duplicates();
            break;
        case 9:
            if (check_palindrome())
            {
                printf("The linked list is palindrome \n");
            }
            else
            {
                printf("The linked list is not palindrome\n");
            }
            break;
        case 10:
            reverse_even();
            break;
        // case 11:
        //     merge_driver();
        //     break;
        case 12:
            reverse_linked_list();
            break;
        case 13:
            sort_linked_list();
            break;
        case 14:
            insert_in_sorted_order();
            break;
        case 15:
            last_divisible_node();
            break;
        default:
            printf("Invalid choice!!!!!!!\n");
            break;
        }
    } while (ch != 0);

    return 0;
}