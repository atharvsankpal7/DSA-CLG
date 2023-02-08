#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 100

int move[MAX];

void initMoveArray() {
    int i;
    for (i = 0; i < MAX; i++) {
        move[i] = -1;
    }
}

int getMinThrows(int *move, int n) {
    int visited[n];
    int queue[n];
    int front = 0, rear = 0;
    int curr;
    int i;
    for (i = 0; i < n; i++) {
        visited[i] = INT_MAX;
    }
    visited[0] = 0;
    queue[rear++] = 0;
    while (front != rear) {
        curr = queue[front++];
        for (i = curr + 1; i <= (curr + 6) && i < n; i++) {
            if (visited[i] == INT_MAX) {
                queue[rear++] = i;
                visited[i] = visited[curr] + 1;
                if (move[i] != -1) {
                    queue[rear++] = move[i];
                    visited[move[i]] = visited[curr] + 1;
                    break;
                }
            }
        }
    }
    return visited[n - 1];
}

int main(void) {
    int t, n, m, i, a, b;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        initMoveArray();
        for (i = 0; i < m; i++) {
            scanf("%d%d", &a, &b);
            move[a - 1] = b - 1;
        }
        printf("%d\n", getMinThrows(move, n));
    }
    return 0;
}