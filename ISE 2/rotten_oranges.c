#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int front = -1, rear = -1;

struct Queue
{
    int i;
    int j;
    int time;
} queue[10000];

void push(int i, int j, int t)
{
    if (rear == 10000 - 1)
    {
        printf("Queue is full.\n");
    }
    else
    {
        rear++;
        queue[rear].i = i;
        queue[rear].j = j;
        queue[rear].time = t;
    }
}

void pop(int *i, int *j, int *t)
{
    if (front == rear)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        front++;
        *i = queue[front].i;
        *j = queue[front].j;
        *t = queue[front].time;
    }
}

int main()
{
    int t, r, c, time = 0, drow[4] = {-1, 0, 0, 1}, dcol[4] = {0, -1, 1, 0};
    bool flag = false;

    printf("Enter the number of test cases --> ");
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        printf("Enter the number of rows and columns respectively for test case %d-->", i + 1);
        scanf("%d%d", &r, &c);
        int matrix[r][c];

        printf("Fill the spaces in the matrix\t \"0\" for empty space  \"1\" for fresh orange  \"2\" for rotten orange\n");
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                scanf("%d", &matrix[i][j]);
                if (matrix[i][j] == 2)
                {
                    push(i, j, 0);
                }
            }
        }

        while (front != rear && rear != -1)
        {
            int i_index, j_index, neighbour_r, neighbour_c;
            pop(&i_index, &j_index, &time);

            for (int i = 0; i < 4; i++)
            {
                neighbour_r = i_index + drow[i];
                neighbour_c = j_index + dcol[i];
                if (neighbour_r >= 0 && neighbour_r < r && neighbour_c >= 0 && neighbour_c < c && matrix[neighbour_r][neighbour_c] == 1)
                {
                    matrix[neighbour_r][neighbour_c] = 2;
                    push(neighbour_r, neighbour_c, time + 1);
                }
            }
        }

        flag = true;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (matrix[i][j] == 1)
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
            {
                break;
            }
        }

        if (flag)
        {
            printf("The time required to rot all the oranges is %d\n", time);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
