#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
} NODE;
NODE *insert(NODE *p, int digit)
{
    if (p == NULL)
    {
        p = (NODE *)malloc(sizeof(NODE));
        p->data = digit;
        p->lchild = NULL;
        p->rchild = NULL;
        return p;
    }
    else
    {
        if (p->data > digit)
        {
            p->lchild = insert(p->lchild, digit);
        }
        else
        {
            p->rchild = insert(p->rchild, digit);
        }
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
void preorder(NODE *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
int sum = 0;
void sum_left_child(NODE *p)
{

    if (p == NULL)
    {
        printf("%d", sum);
    }
    else
    {
        sum += p->data;
        sum_left_child(p->lchild);
    }
}
int main()
{
    NODE *root = NULL;
    root = insert(root, 14);
    root = insert(root, 4);
    root = insert(root, 114);
    root = insert(root, 24);
    root = insert(root, 7);
    root = insert(root, 6);
    postorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    sum_left_child(root);
    return 0;
}