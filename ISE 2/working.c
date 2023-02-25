#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int R, C;
bool visited[MAX_SIZE][MAX_SIZE];

// Struct to represent a cell in the matrix
struct Cell
{
    int row;
    int col;
    int time;
};

// Function to check if a given cell is safe to visit
bool isSafe(int row, int col, int matrix[R][C])
{
    return (row >= 0 && row < R && col >= 0 && col < C && matrix[row][col] == 1 && !visited[row][col]);
}

// Function to rot the oranges and return the time required
int rotOranges(int matrix[R][C])
{
    int time = -1;

    // Initialize the queue
    struct Cell queue[MAX_SIZE];
    int front = -1;
    int rear = -1;

    // Enqueue all rotten oranges into the queue and mark them as visited
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (matrix[i][j] == 2)
            {
                struct Cell c = {i, j, 0};
                queue[++rear] = c;
                visited[i][j] = true;
            }
        }
    }

    // Perform BFS on the matrix
    while (front < rear)
    {
        struct Cell c = queue[++front];
        int row = c.row;
        int col = c.col;
        int curr_time = c.time;
        time = curr_time;

        // Check all four adjacent cells
        if (isSafe(row - 1, col, matrix))
        { // Top
            struct Cell c = {row - 1, col, curr_time + 1};
            queue[++rear] = c;
            visited[row - 1][col] = true;
            matrix[row - 1][col] = 2;
        }
        if (isSafe(row + 1, col, matrix))
        { // Bottom
            struct Cell c = {row + 1, col, curr_time + 1};
            queue[++rear] = c;
            visited[row + 1][col] = true;
            matrix[row + 1][col] = 2;
        }
        if (isSafe(row, col - 1, matrix))
        { // Left
            struct Cell c = {row, col - 1, curr_time + 1};
            queue[++rear] = c;
            visited[row][col - 1] = true;
            matrix[row][col - 1] = 2;
        }
        if (isSafe(row, col + 1, matrix))
        { // Right
            struct Cell c = {row, col + 1, curr_time + 1};
            queue[++rear] = c;
            visited[row][col + 1] = true;
            matrix[row][col + 1] = 2;
        }
    }

    // Check if any fresh oranges remain
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (matrix[i][j] == 1)
            {
                return -1;
            }
        }
    }

    // Return the time required to rot all oranges
    return time;
}

// Driver function
int main()
{
    int t;
    printf("Enter the number of test cases --> ");
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        printf("Enter the number of rows and columns respectively for test case %d-->", i + 1);
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
