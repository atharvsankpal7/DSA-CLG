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
    for (int i = 0; i < 15 - 1; i++)
    {
        for (int j = 0; j < 15 - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}
void selection_sort(int a[])
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = i; j < 15; j++)
        {
            if (a[i] > a[j])
            {
                swap(&a[i], &a[j]);
            }
        }
    }
}
void insertion_sort(int a[])
{
    for (int i = 0; i < 15; i++)
    {
        int j = i - 1 ;
        int temp = a[i];
        while (a[j] > temp && j > -1)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}
int main()
{
    int arr[15] = {1, 52, 556, 5, 265, 66, 4, 4, 6, 6, 656, 4, 11, 65, 46};
    bubble_sort(arr);
    print_arr(arr);
    return 0;
}