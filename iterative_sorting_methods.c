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
        /*
        The last element for first iteration will be largest element and for second iteration will be
        second largest element so the array is automatically being sorted from right side so we are
        reducing the range for each iteration in the relative fashion.
        That's why in the condition for j is `j<15-1-i`.
        */
        for (int j = i; j < 15 - 1 - i; j++)
        {
            if (a[j + 1] < a[j]) // pushing the larger element to the greater index
                swap(&a[j + 1], &a[j]);
        }
    }
}
void selection_sort(int a[])
{
    for (int i = 0; i < 15 - 1; i++)
    {
        /*The comparision of an element will start with the element
        next to it so we are initializing the j as `j=i+1`.
         */
        for (int j = i + 1; j < 15; j++)
        {
            if (a[i] > a[j])
                swap(&a[i], &a[j]);
        }
    }
}
void insertion_sort(int a[])
{
    int j, temp;
    for (int i = 0; i < 15; i++)
    {
        j = i - 1;
        temp = a[i];
        /*
        temp should be used instead of a[i] since a[i] can be
        changed during first iteration.

        the j can also go behind the 0 so that condition
        also should be considered.
        */
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        // j is decreased so we are using j+1
        a[j + 1] = temp;
    }
}
int main()
{
    int arr[15] = {1, 52, 556, 5, 265, 66, 4, 4, 6, 6, 656, 4, 11, 65, 46};
    selection_sort(arr);
    print_arr(arr);
    return 0;
}