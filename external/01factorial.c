#include <stdio.h>
int fact(int a)
{
    if (a == 0 || a == 1)
    {
        return 1;
    }
    else
    {
        return a * fact(a - 1);
    }
}

int main()
{
    printf("%d", fact(5));
    return 0;
}