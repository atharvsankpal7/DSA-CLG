#include <stdio.h>
int a[10] = {61, 32, 13, 4, 35, 66, 27, 83, 19, 18};
int b[10];
void merge(int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] > a[j])
        {
            b[k] = a[j];
            j++;
        }
        else
        {
            b[k] = a[i];
            i++;
        }
        k++;
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++, k++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        j++, k++;
    }
    for ( i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}
void mergesort(int low, int high)
{
    int mid = (low + high) / 2;
    if (low < high)
    {
        mergesort(low, mid);
        mergesort(mid + 1, high);
        merge(low, mid, high);
    }
}
int main()
{
    mergesort(0, 10);
    int i;
	for ( i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
