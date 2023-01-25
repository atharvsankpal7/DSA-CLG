#include <stdio.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void enqueue(int data) {
    if (size == MAX_SIZE) {
        printf("Queue is full!\n");
    } else {
        queue[size] = data;
        int i = size - 1;
        while (i >= 0 && queue[i] > data) {
            swap(&queue[i], &queue[i + 1]);
            i--;
        }
        size++;
    }
}

int dequeue() {
    if (size == 0) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        int data = queue[size - 1];
        size--;
        return data;
    }
}

int main() {
    enqueue(5);
    enqueue(3);
    printf("Dequeued element: %d\n", dequeue());
    enqueue(7);
    enqueue(2);
    printf("Dequeued element: %d\n", dequeue());
    printf("Dequeued element: %d\n", dequeue());
    printf("Dequeued element: %d\n", dequeue());
    enqueue(1);
    printf("Dequeued element: %d\n", dequeue());
    return 0;
}
