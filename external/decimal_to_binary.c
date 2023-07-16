#include <stdio.h>

int decimal_to_binary(int a)
{
    printf("The number %d in binary is ", a);
    int arr[4]={0,0,0,0};
    for (int i = 0; i < 4; i++)
    {
        arr[3 - i] = a % 2;
        a /= 2;
    }
    for (int i = 0; i < 4; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}
int main()
{
    for (int i = 1; i <= 10; i++)
    {
        decimal_to_binary(i);
    }

    return 0;
}