#include <stdio.h>
#include <stdlib.h>

int coin_change(int S[], int m, int n)
{
    int table[n + 1];
    table[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        table[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = S[i]; j <= n; j++)
        {
            table[j] += table[j - S[i]];
        }
    }
    return table[n];
}

int main()
{
    int n, size;
    printf("Enter the target : ");
    scanf("%d", &n);
    printf("Enter the no of denominations : ");
    scanf("%d", &size);
    printf("Enter the denominations :\n");
    int S[n];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &S[i]);
    }
    int m = size;
    printf("The total number of ways is: %d\n", coin_change(S, m, n));
    return 0;
}