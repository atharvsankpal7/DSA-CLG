/*
Name- Atharv Santosh Sankpal
URN - 21031040
Practical NO - 7
Practical Title - Infix to postfix
*/
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100  // max size of infix expression

char stack[MAX_SIZE];  // stack for operators
int top = -1;          // top of stack

// function to check if character is operator
int isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
        return 1;
    }
    return 0;
}

// function to check precedence of operators
int precedence(char ch) {
    if (ch == '^') {
        return 3;
    } else if (ch == '*' || ch == '/') {
        return 2;
    } else if (ch == '+' || ch == '-') {
        return 1;
    } else {
        return -1;
    }
}

// function to perform operation
void push(char ch) {
    stack[++top] = ch;
}

// function to pop from stack
char pop() {
    if (top == -1) {
        return -1;
    }
    return stack[top--];
}

// function to convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char ch;
    stack[++top] = '#';

    // iterate through infix expression
    for (i = 0; i < strlen(infix); i++) {
        ch = infix[i];

        // if character is operand
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {  // if character is '('
            push(ch);
        } else if (ch == ')') {  // if character is ')'
            while (stack[top] != '#' && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();
        } else {  // if character is operator
            while (stack[top] != '#' && precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // pop remaining operators from stack
    while (stack[top] != '#') {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';  // set end of postfix expression
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);

    printf("Infix expression: %s\n", infix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}

