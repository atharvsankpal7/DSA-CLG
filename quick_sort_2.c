#include <stdio.h>
void print_arr(int a[])
{
    for (int i = 0; i < 15; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int partition(int low, int high, int a[])
{
    int i = low, j = high, pivot = a[low];
    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (j > i);
    int temp = a[j];
    a[j] = a[low];
    a[low] = temp;
    return j;
}
void quick_sort(int a[], int low, int high)
{
    if (low < high)
    {
        int pindex = partition(low, high, a);
        quick_sort(a, low, pindex - 1);
        quick_sort(a, pindex + 1, high);
    }
}
int main()
{
    int arr[15] = {1, 52, 556, 5, 265, 66, 4, 4, 6, 6, 656, 4, 11, 65, 46};
    quick_sort(arr, 0, 14);
    print_arr(arr);
    return 0;
}