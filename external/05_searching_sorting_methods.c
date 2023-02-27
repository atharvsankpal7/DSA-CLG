#include <stdio.h>
#include <stdbool.h>
void print_array(int a[])
{
    printf("The array after performing operation is -->\n");
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void unsort(int arr[])
{
    int a[20] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 4, 5, 6, 1, 2, 3};
    for (int i = 0; i < 20; i++)
    {
        arr[i] = a[i];
    }
    print_array(arr);
}

void bubble_sort(int a[])
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20 - 1; j++)
        {
            if (a[i] < a[j])
            {
                swap(&a[i], &a[j]);
            }
        }
    }
    print_array(a);
}
void selection_sort(int a[])
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20 - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
    print_array(a);
}
void insertion_sort(int a[])
{
    int temp, j;
    for (int i = 0; i < 20; i++)
    {
        j = i - 1;
        temp = a[i];
        while (a[j] > temp && j > -1)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
    print_array(a);
}
int b[20];
void merge(int low, int mid, int high, int a[])
{
    int i = low, j = mid + 1, k = low;
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
    for (int x = low; x <= high; x++)
    {
        a[x] = b[x];
    }
}
void merge_sort(int low, int high, int a[])
{
    int mid = (low + high) / 2;
    if (low < high)
    {
        merge_sort(low, mid, a);
        merge_sort(mid + 1, high, a);
        merge(low, mid, high, a);
    }
    // To see the change in array with every iteration
    // print_array(a);
}
int partition(int low, int high, int a[])
{
    int i = low + 1, j = high, pivot = a[low];
    do
    {
        while (a[i] < pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(&a[i], &a[j]);
        }
    } while (i < j);
    swap(&a[low], &a[j]);
    return j;
}
void quick_sort(int low, int high, int a[])
{
    if (low < high)
    {
        int pindex = partition(low, high, a);
        quick_sort(low, pindex - 1, a);
        quick_sort(pindex + 1, high, a);
    }
}
bool linear_search(int a[], int key)
{
    for (int i = 0; i < 20; i++)
    {
        if (a[i] == key)
            return true;
    }
    return false;
}
bool binary_search(int a[], int key)
{
    bubble_sort(a);
    int low = 0, high = 20, mid;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (key == a[mid] || key == a[low])
        {
            return true;
        }
        else if (key > a[mid])
        {
            low = mid + 1;
        }
        else if (key < a[mid])
        {
            high = mid - 1;
        }
    }
    return false;
}
int main()
{
    int arr[20] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 4, 5, 6, 1, 2, 3}, ch;
    int key;
    do
    {
        printf("1.Bubble sort\n2.Selection sort\n3.Insertion sort\n4.Merge sort\n5.Quick Sort\n6.Linear Search\n7.Binary Search\n8.Unsort the array\n0.EXIT\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            bubble_sort(arr);
            break;
        case 2:
            selection_sort(arr);
            break;
        case 3:
            insertion_sort(arr);
            break;
        case 4:
            merge_sort(0, 20, arr);
            print_array(arr);
            break;
        case 5:
            quick_sort(0, 20, arr);
            print_array(arr);
            break;
        case 6:

            printf("Enter the element that you want to search in the array--> ");
            scanf("%d", &key);
            if (linear_search(arr, key))
                printf("The number is present in the array\n");
            else
                printf("The number is not present in the array\n");
            break;
        case 7:

            printf("Enter the element that you want to search in the array--> ");
            scanf("%d", &key);
            if (binary_search(arr, key))
                printf("The number is present in the array\n");
            else
                printf("The number is not present in the array\n");
            break;

        case 8:
            unsort(arr);
            break;

        case 0:
            printf("The program has been terminated\n");
            break;

        default:
            printf("INVALID CHOICE !!!!\n");
            break;
        }
    } while (ch != 0);

    return 0;
}