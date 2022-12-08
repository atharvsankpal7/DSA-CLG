/*
Name- Atharv Santosh Sankpal
URN - 21031040
Practical NO - 1
Practical Title - Recursion
*/
#include <stdio.h>
int factorial(int a)
{
    if (a == 0 || a == 1)
    {
        return 1;
    }
    else
    {
        return a * factorial(a - 1);
    }
}
int main()
{
    int a;
    printf("Enter the number whose factorial has to be found -->");
    scanf("%d", &a);
    printf("The factorial of the number is %d", factorial(a));
}