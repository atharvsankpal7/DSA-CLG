#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};
typedef struct node NODE;
NODE *root = NULL;

// Insert Operations
NODE *insert(NODE *p, int data)
{
    if (p == NULL)
    {
        NODE *node = (NODE *)malloc(sizeof(NODE));
        node->lchild = NULL;
        node->rchild = NULL;
        node->data = data;
        return node;
    }
    if (data < p->data)
    {
        p->lchild = insert(p->lchild, data);
    }
    else
    {
        p->rchild = insert(p->rchild, data);
    }
}

// search operation
bool search(NODE *p, int data)
{
    p = root;
    while (p != NULL)
    {
        if (data < p->data)
        {
            p = p->lchild;
        }
        else if (data > p->data)
        {
            p = p->rchild;
        }
        else
        {
            return true;
        }
    }
    return false;
}

// Traversal methods
void inorder(NODE *p)
{

    if (p != NULL)
    {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

void preorder(NODE *p)
{

    if (p != NULL)
    {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void postorder(NODE *p)
{

    if (p != NULL)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ", p->data);
    }
}

int main()
{
    int data, opt, found;

    printf("Enter data at root node = ");
    scanf("%d", &data);
    root = insert(root, data);

    while (1)
    {
        printf("\n\n1.Add new node\n2.Search node\n3.In order traversal\n4.Pre order traversal\n5.Post order traversal\n6.Exit\n Choose = ");

        scanf("%d", &opt);
        if (opt == 6)
        {
            break;
        }

        switch (opt)
        {
        case 1:
            printf("Enter data at node = ");
            scanf("%d", &data);
            insert(root, data);
            break;

        case 2:
            printf("Enter searching node = ");
            scanf("%d", &data);
            found = search(root, data);

            if (found)
            {
                printf("%d value is found in the tree", data);
            }
            else
            {
                printf("%d value not found", data);
            }
            break;

        case 3:
            printf("The tree traversal inorder is -->\n");
            inorder(root);
            printf("\n");
            break;

        case 4:
            printf("The tree traversal preorder is -->\n");
            preorder(root);
            printf("\n");
            break;

        case 5:
            printf("The tree traversal postorder is -->\n");
            postorder(root);
            printf("\n");
            break;
        }
    }

    return 0;
}