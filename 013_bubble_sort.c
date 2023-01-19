#include <stdio.h>
int main()
{
    int arr[15] = {50, 2, 18, 321, 53, 0, 15, 67, 3, 5, 654, 364, 34, 11, 30};
    for (int i = 0; i < 15 - 1; i++)
    {
        for (int j = 0; j < 15 - 1 - i; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < 15; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}