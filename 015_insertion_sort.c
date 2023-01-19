// Insertion sort
#include <stdio.h>
int main()
{
    int arr[15] = {1, 52, 556, 5, 265, 66, 4, 4, 6, 6, 656, 4, 11, 65, 46}, j;
    for (int i = 1; i < 15 - 1; i++)
    {
        int temp = arr[i];
        j = i - 1;
        while (j >= 0 && temp < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    for (int i = 0; i < 15; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}