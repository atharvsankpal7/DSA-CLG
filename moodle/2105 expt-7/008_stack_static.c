/*
Name- Atharv Santosh Sankpal
URN - 21031040
Practical NO - 7
Practical Title - Implementing stack using array
*/
#include <stdio.h>
int arr[5], top = -1, ch;
void push()
{
    if (top == 4)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        printf("Enter the data --> ");
        scanf("%d", &arr[top]);
    }
}
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("%d has been popped\n", arr[top]);
        top--;
    }
}
void traverse()
{
    if (top == -1)
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("The stack is as follows :");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}
int main()
{

    do
    {
        printf("1.Push\n2.Pop\n3.Traverse\n4.EXIT!! \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            traverse();
            break;
        case 4:
            printf("The program has been terminated\n");
            break;
        default:
            printf("INVALID CHOICE!!!\n");
            break;
        }
    } while (ch != 5);

    return 0;
}