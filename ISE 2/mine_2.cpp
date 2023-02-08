
#include <stdio.h>
#include <stdbool.h>

int front = 0, rear = -1;
struct Queue
{
	int i_index;
	int j_index;
	int time;
} queue[10000];

void push(int i, int j, int t)
{
	rear++;
	queue[rear].i_index = i;
	queue[rear].j_index = j;
	queue[rear].time = t;
}

void pop(int *i, int *j, int *t)
{
	front++;
	*i = queue[front].i_index;
	*j = queue[front].j_index;
	*t = queue[front].time;
}

bool queue_empty_check()
{
	return front > rear;
}

int main()
{
	int t, r, c, time = 0, flag = 1, drow[4] = {-1, 0, 0, +1}, dcol[4] = {0, -1, +1, 0};
	printf("Enter the number of test cases --> ");
	scanf("%d", &t);
	for (int x = 0; x < t; x++)
	{
		printf("Enter the number of rows and columns respectively for test case %d-->", x + 1);
		scanf("%d%d", &r, &c);
		int matrix[r][c];
		printf("Fill the spaces in the matrix\t \"0\" for empty space  \"1\" for fresh orange  \"2\" for rotten orange\n");
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				scanf("%d", &matrix[i][j]);
			}
		}
		while (queue_empty_check())
		{
			int i_index, j_index, neighbour_c, neighbour_r;
			pop(&i_index, &j_index, &time);

			for (int i = 0; i < 4; i++)
			{
				neighbour_c = j_index + dcol[i];
				neighbour_r = i_index + drow[i];

				if (neighbour_c >= 0 && neighbour_r >= 0 && neighbour_c < c && neighbour_r < c && matrix[i_index][j_index] == 1)
				{
					matrix[i_index][j_index] = 2;
					push(neighbour_r, neighbour_c, time + 1);
					flag = 1;
				}
			}
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (matrix[i][j] == 1)
				{
					flag = 0;
					break;
				}
				else
				{
					flag = 1;
				}
			}
		}
		if (flag != 0)
		{
			printf("The time required to rot all the oranges is %d\n", time);
		}
		else
		{
			printf("All oranges could not be rotted\n");
		}
	}
	return 0;
}