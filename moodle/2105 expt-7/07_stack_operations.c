/*
Name- Atharv Santosh Sankpal
URN - 21031040
Practical NO - 7
Practical Title - Checking balanced
*/
#include <stdio.h>
int main()
{
    char string[100], stack[100];
    int flag = -1, top = -1;
    printf("Enter the string -->");
    scanf("%s", &string);
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == '{' || string[i] == '[' || string[i] == '(')
        {
            top++;
            stack[top] = string[i];
            flag = -1;
        }
        else if (string[i] == '}')
        {
            if (top == -1)
            {
                flag = -1;
                break;
            }
            if (stack[top] = '{')
            {
                top--;
                flag = 0;
            }
            else
            {
                flag = -1;
                break;
            }
        }
        else if (string[i] == ')')
        {
            if (top == -1)
            {
                flag = -1;
                break;
            }
            if (stack[top] == '(')
            {
                top--;
                flag = 0;
            }
            else
            {
                flag = -1;
                break;
            }
        }
        else if (string[i] == ']')
        {
            if (top == -1)
            {
                flag = -1;
                break;
            }
            if (stack[top] == '[')
            {
                top--;
                flag = 0;
            }
            else
            {
                flag = -1;
                break;
            }
        }
    }
    if (flag == 0)
    {
        printf("The string is balanced\n");
    }
    else
    {
        printf("The string is unbalanced\n");
    }
    return 0;
}