#include <stdio.h>
int d = 0;
int main()
{
    int front = -1, rear = -1, arr[5], ch;
    do
    {
        printf("1.Enqueue\n2.Dequeue\n3.Traverse\n4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (front == (rear + 1) % 5)
            {
                printf("QueueOverflow\n");
            }
            else
            {
                if (rear == -1)
                {
                    front = 0;
                    rear = 0;
                }
                else
                {
                    rear = (rear + 1) % 5;
                    printf("%d ", rear);
                }
                printf("Enter the data --> ");
                scanf("%d", &arr[rear]);
            }
            break;
        case 2:
            if (front == -1)
            {
                printf("QueueUnderflow\n");
            }
            else
            {
                d = 1;
                if (front == rear)
                {
                    printf("%d has been removed\n", arr[front]);
                    front = -1;
                    rear = -1;
                }
                else
                {
                    printf("%d has been removed\n", arr[front]);
                    front = (front + 1) % 5;
                }
            }
            break;
        case 3:
            if (front == -1)
            {
                printf("Queue is empty\n");
            }
            else
            {
                int x = 0;
                printf("The queue is as follows\n");
                for (int i = front; i <= rear; i = (i + 1) % 5)
                {
                    if (i == 0)
                    {
                        x++;
                        if (d == 1)
                        {
                            d = 0;
                            x++;
                        }
                    }
                    if (x == 2)
                    {
                        x = 0;
                        break;
                    }
                    printf("%d ", arr[i]);
                }
                printf("\n");
            }
            break;
        case 4:
            printf("The program has terminated successfully\n");
            break;
        default:
            printf("Invalid choice !!!!\n");
            break;
        }
    } while (ch != 4);

    return 0;
}