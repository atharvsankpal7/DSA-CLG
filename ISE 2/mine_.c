#include <stdio.h>
#include <stdbool.h>
#define EMPTY 0
#define FRESH 1
#define ROTTEN 2

int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

typedef struct queue
{
    int front;
    int rear;
    int currItemCount;
    int *arrayRow;
    int *arrayCol;
} queue_t;

queue_t *createQueue(int queueSize)
{
    queue_t *queue = malloc(sizeof(queue_t));
    if (!queue)
    {
        return NULL;
    }
    queue->front = 0;
    queue->rear = -1;
    queue->currItemCount = 0;
    queue->arrayRow = malloc(sizeof(int) * queueSize);
    queue->arrayCol = malloc(sizeof(int) * queueSize);
    if (!queue->arrayRow || !queue->arrayCol)
    {
        return NULL;
    }
    return queue;
}

bool isQueueEmpty(queue_t *queue)
{
    return queue->currItemCount == 0;
}

void queueEnqueue(queue_t *queue, int rowIdx, int colIdx)
{
    queue->arrayRow[++queue->rear] = rowIdx;
    queue->arrayCol[queue->rear] = colIdx;
    queue->currItemCount++;
}

int queueDequeueRow(queue_t *queue)
{
    return queue->arrayRow[queue->front];
}

int queueDequeueCol(queue_t *queue)
{
    queue->currItemCount--;
    return queue->arrayCol[queue->front++];
}

void freeQueue(queue_t *queue)
{
    free(queue->arrayRow);
    free(queue->arrayCol);
    free(queue);
}

void printQueue(queue_t *queue, int queueSize)
{
    printf("Row:    [");
    for (int i = 0; i < queueSize; i++)
    {
        printf("%d,", queue->arrayRow[i]);
    }
    printf("]\n");
    printf("Column: [");
    for (int i = 0; i < queueSize; i++)
    {
        printf("%d,", queue->arrayCol[i]);
    }
    printf("]\n");
}

int orangesRotting(int **grid, int gridSize, int *gridColSize)
{

    if ((gridSize == 0) || (*gridColSize == 0))
    {
        return 0;
    }

    int numOfRows = gridSize;
    int numOfCols = *gridColSize;
    int freshOranges = 0;
    int queueSize = numOfCols * numOfRows * 2;

    queue_t *queue = createQueue(queueSize);

    for (int i = 0; i < numOfRows; i++)
    {
        for (int j = 0; j < numOfCols; j++)
        {
            if (grid[i][j] == ROTTEN)
            {
                queueEnqueue(queue, i, j);
            }
            else if (grid[i][j] == FRESH)
            {
                freshOranges++;
            }
        }
    }

    queueEnqueue(queue, -1, -1);
    int minutesElapsed = -1;
    // printQueue(queue, numOfRows, numOfCols);
    while (!isQueueEmpty(queue))
    {
        // printQueue(queue, queueSize);
        int rowIdx = queueDequeueRow(queue);
        int colIdx = queueDequeueCol(queue);
        if (rowIdx == -1)
        {
            minutesElapsed++;
            if (!isQueueEmpty(queue))
            {
                queueEnqueue(queue, -1, -1);
            }
            // printf("\nAdding -1 again\n");
            // printQueue(queue, queueSize);
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                int r = rowIdx + directions[i][0];
                int c = colIdx + directions[i][1];
                if (r >= 0 && r < numOfRows && c >= 0 && c < numOfCols)
                {
                    if (grid[r][c] == FRESH)
                    {
                        grid[r][c] = ROTTEN;
                        freshOranges--;
                        queueEnqueue(queue, r, c);
                    }
                }
            }
            // printQueue(queue, queueSize);
        }
    }

    freeQueue(queue);
    return freshOranges == 0 ? minutesElapsed : -1;
}
int main()
{
    int gridSize = 3;
    int gridColSize[3] = {3, 3, 3};
    int **grid = (int **)malloc(gridSize * sizeof(int *));
    for (int i = 0; i < gridSize; i++)
    {
        grid[i] = (int *)malloc(gridColSize[i] * sizeof(int));
    }
    grid[0][0] = ROTTEN;
    grid[0][1] = ROTTEN;
    grid[0][2] = ROTTEN;
    grid[1][0] = FRESH;
    grid[1][1] = FRESH;
    grid[1][2] = ROTTEN;
    grid[2][0] = FRESH;
    grid[2][1] = FRESH;
    grid[2][2] = FRESH;

    int result = orangesRotting(grid, gridSize, gridColSize);
    printf("Result: %d\n", result);

    for (int i = 0; i < gridSize; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return 0;
}