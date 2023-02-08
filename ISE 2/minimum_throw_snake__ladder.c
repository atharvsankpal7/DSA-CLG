#include <stdio.h>
#include <stdlib.h>

int solve(int (*ladders)[2], int (*snakes)[2], int laddersSize, int snakesSize)
{
    int i, j;
    int edges[101] = {0};
    for (i = 0; i < laddersSize; i++)
    {
        edges[ladders[i][0]] = ladders[i][1];
    }
    for (i = 0; i < snakesSize; i++)
    {
        edges[snakes[i][0]] = snakes[i][1];
    }
    int u[101] = {0};
    int v[101] = {0};
    int m = 0;
    v[1] = 1;
    while (v[100] == 0)
    {
        m++;
        int w[101] = {0};
        for (i = 0; i < 101; i++)
        {
            if (v[i] == 1)
            {
                for (j = 1; j <= 6; j++)
                {
                    int n = i + j;
                    if (n > 100)
                    {
                        continue;
                    }
                    if (edges[n] != 0)
                    {
                        n = edges[n];
                    }
                    if (u[n] == 1)
                    {
                        continue;
                    }
                    u[n] = 1;
                    w[n] = 1;
                }
            }
        }
        for (i = 0; i < 101; i++)
        {
            v[i] = w[i];
        }
    }
    return m;
}

int main()
{
    int ladders[4][2] = {{11, 40}, {37, 67}, {47, 73}, {15, 72}};
    int snakes[6][2] = {{90, 12}, {98, 31}, {85, 23}, {75, 42}, {70, 18}, {49, 47}};
    printf("%d\n", solve(ladders, snakes, 4, 6));
    return 0;
}
