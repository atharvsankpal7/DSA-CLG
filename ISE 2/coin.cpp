#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 1001

int arr[MAX_N];

void push_queue(int *queue, int *front, int *rear, int value)
{
    (*rear)++;
    queue[*rear] = value;
}

int pop_queue(int *queue, int *front, int *rear)
{
    (*front)++;
    return queue[*front - 1];
}
//if front>rear return true else return false
bool is_empty(int front, int rear)
{
    return front > rear;
}

void rotation(int n, int *ans)
{
    int queue[MAX_N];
    int front = 0, rear = -1;
    int i, j;

    for (i = 1; i <= n; i++)
    {
        push_queue(queue, &front, &rear, i);
    }

    i = 1;
    while (!is_empty(front, rear))
    {
        j = 0;
        while (j < i)
        {
            int x = pop_queue(queue, &front, &rear);
            push_queue(queue, &front, &rear, x);
            j++;
        }

        int x = pop_queue(queue, &front, &rear);
        if (arr[x] != 0)
        {
            *ans = -1;
            return;
        }
        arr[x] = i;
        i++;
    }
    // copying the array into the answer with one earlier index
    for (int i = 0; i < n; i++)
    {
        ans[i] = arr[i + 1];
    }
}

int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int ans[n];
        // setting the value of the whole array to `0`
        for (int i = 0; i < n; i++)
        {
            arr[i] = 0;
        }
        //calling the rotation function for each of set of cards
        rotation(n, ans);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
