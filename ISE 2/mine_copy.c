#include <stdio.h>
#include <stdbool.h>
int R, C;

// Checking if the cell exist or not
bool issafe(int i, int j)
{
    if (i >= 0 && i < R && j >= 0 && j < C)
        return true;
    return false;
}

int rotOranges(int v[R][C])
{
    bool changed = false;
    int no = 2;
    while (true)
    {
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (v[i][j] == no)
                {
                    if (issafe(i + 1, j) && v[i + 1][j] == 1)
                    {
                        v[i + 1][j] = v[i][j] + 1;
                        changed = true;
                    }
                    if (issafe(i, j + 1) && v[i][j + 1] == 1)
                    {
                        v[i][j + 1] = v[i][j] + 1;
                        changed = true;
                    }
                    if (issafe(i - 1, j) && v[i - 1][j] == 1)
                    {
                        v[i - 1][j] = v[i][j] + 1;
                        changed = true;
                    }
                    if (issafe(i, j - 1) && v[i][j - 1] == 1)
                    {
                        v[i][j - 1] = v[i][j] + 1;
                        changed = true;
                    }
                }
            }
        }

        if (!changed)
            break;
        changed = false;
        no++;
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (v[i][j] == 1)
                return -1;
        }
    }

    return no - 2;
}

int main()
{
    int t;
    printf("Enter the number of test cases --> ");
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        printf("Enter the number of rows and columns respectively for test case %d -->", i + 1);
        scanf("%d%d", &R, &C);
        int matrix[R][C];
        printf("Fill the spaces in the matrix\t \"0\" for empty space  \"1\" for fresh orange  \"2\" for rotten orange\n");
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                scanf("%d", &matrix[i][j]);
            }
        }
        printf("The time required to rot oranges is %d\n", rotOranges(matrix));
    }
    return 0;
}