#include <stdio.h>
int main()
{
    int mid, low, high, arr[100], key, flag = 0;
    printf("Enter the number that you want to search :");
    scanf("%d", &key);
    for (int i = 0; i < 100; i++)
    {
        arr[i] = i + 1;
    }
    low = 0, high = 99;
    mid = (low + high) / 2;
    while (low <= high)
    {
        if (key == arr[mid])
        {
            flag = 1;
            break;
        }
        if (key < arr[mid])
        {
            high = mid - 1;
        }
        if (key > arr[mid])
        {
            low = mid + 1;
        }

        mid = (low + high) / 2;
    }
    if (flag == 1)
    {
        printf("Search Successful\n");
    }
    else
    {
        printf("Search Unsuccessful\n");
    }
    return 0;
}