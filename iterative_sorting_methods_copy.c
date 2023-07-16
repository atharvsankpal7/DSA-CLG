#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
void print_arr(int a[])
{
    for (int i = 0; i < 15; i++)
        printf("%d ", a[i]);
    printf("\n");
}
void bubble_sort(int a[])
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15 - i - 1; j++)
        {
            if (a[j] > a[j + 1])
                swap(&a[j], &a[j + 1]);
        }
    }
}
void selection_sort(int a[])
{
    for (int i = 0; i < 15 - 1; i++)
    {
        for (int j = i+1; j < 15; j++)
        {
            if (a[i] > a[j])
                swap(&a[j], &a[i]);
        }
    }
}
void insertion_sort(int a[])
{
    int temp, j;
    for (int i = 0; i < 15; i++)
    {
        j = i - 1;
        temp = a[i];
        while (j > -1 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}
int main()
{
    int arr[15] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 2, 1};
    selection_sort(arr);
    print_arr(arr);
    return 0;
}