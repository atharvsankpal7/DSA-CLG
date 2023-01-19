/*
Name- Atharv Santosh Sankpal
URN - 21031040
Practical NO - 7
Practical Title - Infix to prefix
*/
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100 // max size of infix expression

char stack[MAX_SIZE]; // stack for operators
int top = -1;         // top of stack

// function to check if character is operator
int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
    {
        return 1;
    }
    return 0;
}

// function to check precedence of operators
int precedence(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

// function to perform operation
void push(char ch)
{
    stack[++top] = ch;
}

// function to pop from stack
char pop()
{
    if (top == -1)
    {
        return -1;
    }
    return stack[top--];
}

// function to convert infix to prefix
void infixToPrefix(char infix[], char prefix[])
{
    int i, j = 0;
    char ch;
    stack[++top] = '#';

    // iterate through infix expression
    for (i = strlen(infix) - 1; i >= 0; i--)
    {
        ch = infix[i];

        // if character is operator
        if (isOperator(ch) == 1)
        {
            while (stack[top] != '#' && precedence(stack[top]) >= precedence(ch))
            {
                prefix[j++] = pop();
            }
            push(ch);
        }
        else if (ch == ')')
        { // if character is ')'
            push(ch);
        }
        else if (ch == '(')
        { // if character is '('
            while (stack[top] != '#' && stack[top] != ')')
            {
                prefix[j++] = pop();
            }
            pop();
        }
        else
        { // if character is operand
            prefix[j++] = ch;
        }
    }

    // pop remaining operators from stack
    while (stack[top] != '#')
    {
        prefix[j++] = pop();
    }

    prefix[j] = '\0'; // set end of prefix expression
}

int main()
{
    char infix[MAX_SIZE];
    char prefix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPrefix(infix, prefix);

    printf("Infix expression: %s\n", infix);
    printf("Prefix expression: %s\n", strrev(prefix));

    return 0;
}
