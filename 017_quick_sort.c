#include <stdio.h>
// swapping two numbers
void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
// printing the array of size
void print_arr(int a[])
{
    for (int i = 0; i < 15; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int partition(int a[], int low, int high)
{
    int i = low, pivot = a[low], j = high;
    /*we atleast want to do this shit one time since if `i` has crossed `j` on first iteration
    then we only have 2 elements in the subarray and we want to check if second element is
    greater than the first i.e. `pivot` element */
    do
    {
        /*
        going to the index position where the element will be greater than the `pivot`
        since we want all the greater element on the right side of the `pivot`.
        The smaller one should remain on the left side so will skip over them and stop where we get the larger element.
        */
        while (a[i] <= pivot)
        {
            i++;
        }
        /*
        going to the index position where the element will be smaller than the `pivot`
        since we want all the smaller elements on the left side of the `pivot`.
        The greater one should remain on the right side so we will skip over them and stop where we get the smaller element
        */
        while (a[j] > pivot)
        {
            j--;
        }
        /*
        If the `i` is smaller than the `j` the we will swap the `a[i]` and `a[j]`
        since the condition will be automatically become `a[i]<a[j]` due to skipping over the element
        with respect to the `pivot` element
        the `a[i]` is greater than the pivot and `a[j]` is smaller than the pivot so automatically `a[i]<a[j]`
        */
        if (i < j)
        {
            swap(&a[i], &a[j]);
        }
    } while (i < j);
    /*
        after doing all of this we will get where the `j` will be in the spot where the `pivot` element belongs
        also the element present at `a[j]` will always be smaller than the pivot element after doing the above
        steps so after swapping the elements the smaller element will go on the first position i.e. `a[low]`
        and pivot element will go on to the right position where all the elements at right side of the `a[j]`
        will be greater than the earlier `pivot` element and all to the left side will be smaller ones and 
        the elements which are equal to the `pivot `.
    */
    swap(&a[low], &a[j]);
    /*
    we are returning the right position of the pivot element to divide the array into two subarrays
    where one subarray will have all the smaller and equal numbers and second subarray will have the greater ones.
    */
    return j;
}
void quick_sort(int a[], int low, int high)
{
    if (low < high)
    {
        int partition_index = partition(a, low, high);
        quick_sort(a, low, partition_index - 1);  // For the subarray with smaller and equal elements.
        quick_sort(a, partition_index + 1, high); // For the subarray with greater elements.
    }
}
int main()
{
    int arr[15] = {1, 52, 556, 5, 265, 66, 4, 4, 6, 6, 656, 4, 11, 65, 46};
    quick_sort(arr, 0, 14);
    print_arr(arr);
    return 0;
}