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

NODE *insert(NODE *p, int value)
{
    if (p == NULL)
    {
        p = (NODE *)malloc(sizeof(NODE));
        p->data = value;
        p->lchild = NULL;
        p->rchild = NULL;
    }
    else if (p->data > value)
        p->lchild = insert(p->lchild, value);
    else
        p->rchild = insert(p->rchild, value);
}
bool search(NODE *p, int key)
{
    while (p != NULL)
    {
        if (p->data > key)
            p = p->lchild;
        else if (p->data < key)
            p = p->rchild;
        else
            return true;
    }
    return false;
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
void inorder(NODE *p)
{
    if (p != NULL)
    {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
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
        printf("1.Add new node\n2.Search node\n3.In order traversal\n4.Pre order traversal\n5.Post order traversal\n6.Exit\nChoose = ");

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
                printf("%d value is found in the tree\n", data);
            }
            else
            {
                printf("%d value not found\n", data);
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