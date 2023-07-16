/*
Name- Atharv Santosh Sankpal
URN - 21031040
Practical NO - 9
Practical Title - Searching Techniques
*/
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
        if (arr[mid] == key)
        {
            flag = 1;
            break;
        }
        else if (arr[mid] > key)
        {
            high = mid - 1;
            mid = (low + high) / 2;
        }
        else
        {
            low = mid + 1;
            mid = (low + high) / 2;
        }
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