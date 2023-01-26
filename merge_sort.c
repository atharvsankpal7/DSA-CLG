#include <stdio.h>
int b[15];
int a[15] = {1, 52, 556, 5, 265, 66, 4, 4, 6, 6, 656, 4, 11, 65, 46};
void merge(int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}
void merge_sort(int low, int high)
{
    int mid = (low + high) / 2;
    if (low < high)
    {
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
}
int main()
{
    merge_sort(0, 14);
    for (int i = 0; i < 15; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}