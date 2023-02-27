#include <stdio.h>
int fib(int a)
{
    if (a <= 1)
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
    printf("%d", fib(7));
    return 0;
}