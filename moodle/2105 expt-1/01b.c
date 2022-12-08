/*
Name- Atharv Santosh Sankpal
URN - 21031040
Practical NO - 1
Practical Title - Recursion
*/
#include <stdio.h>

int fib(int a)
{
    if (a == 1)
    {
        return 0;
    }
    if (a == 2)
    {
        return 1;
    }
    else
    {
        return fib(a - 1) + fib(a - 2);
    }
}
int main()
{
    int a;
    printf("Enter the number whose fibonacci has to be found -->");
    scanf("%d", &a);
    printf("%d", fib(a));
}