#include <stdio.h>
#include <stdlib.h>
#define node_no 4

typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *adj[node_no];

void input()
{
    for (int i = 0; i < node_no; i++)
    {
        adj[i] = NULL;
    }
    for (int i = 0; i < node_no; i++)
    {
        int k;
        printf("Number of adjacent noded -->");
        scanf("%d", &k);
        for (int j = 0; j < k; j++)
        {
            NODE *p = (NODE *)malloc(sizeof(NODE));
            printf("Enter the value of the node-->");
            scanf("%d", &p->data);
            if (adj[i] == NULL)
            {
                p->next = NULL;
                adj[i] = p;
            }
            else
            {
                p->next = adj[i];
                adj[i] = p;
            }
        }
    }
}
void print()
{
    for (int i = 0; i < node_no; i++)
    {
        NODE *p = adj[i];
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}
int main()
{
    input();
    print();
    return 0;
}