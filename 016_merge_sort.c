#include <stdio.h>
int a[10] = {61, 32, 13, 4, 35, 66, 27, 83, 19, 18};
int b[10];
void merge(int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            k++, i++;
        }
        else
        {
            b[k] = a[j];
            k++, j++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        k++, i++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        k++, j++;
    }
}
void MergeSort(int low, int high)
{
    int mid = (low + high) / 2;
    if (low < high)
    {
        MergeSort(low, mid);
        MergeSort(mid + 1, high);
        merge(low, mid, high);
    }
}
int main()
{
    MergeSort(0, 9);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", b[i]);
    }
    return 0;
}