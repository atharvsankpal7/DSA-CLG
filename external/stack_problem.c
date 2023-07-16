/*
Check if given expression is balanced expression or not
Given a string containing opening and closing braces, check if it represents a balanced expression or not.
For example, { [ { } { } ] } , { { [ ] } }  are balanced expressions
{ [ } ] , { { [ ] { } ] }  are not balanced expressions.
*/
#include <stdio.h>
#include <string.h>
/*
push -->

*/
int main()
{
    char str[] = "{{[{}{}]}";
    char c;
    int flag = 1;
    char stack[1000];
    int tos = -1;
    for (int i = 0; i < strlen(str); i++)
    {
        c = str[i];
        if (c == '{' || c == '[' || c == '(')
        {
            tos++;
            stack[tos] = c;
        }
        else
        {
            if (c == '}')
            {
                if (stack[tos] == '{')
                {
                    tos--;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
            if (c == ']')
            {
                if (stack[tos] == '[')
                {
                    tos--;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
            if (c == ')')
            {
                if (stack[tos] == '(')
                {
                    tos--;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
        }
    }
    if (flag && tos == -1)
    {
        printf("The expression is balanced\n");
    }
    else
    {
        printf("The expression is not balanced\n");
    }
    return 0;
}