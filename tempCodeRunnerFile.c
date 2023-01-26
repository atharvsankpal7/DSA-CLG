// Iterative sorting methods
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
void selection_sort(int a[])
{
      for (int i = 0; i < 15 - 1; i++)
      {
            for (int j = i + 1; j < 15; j++)
            {
                  if (a[i] > a[j])
                        swap(&a[i], &a[j]);
            }
      }
}
void bubble_sort(int a[])
{
      for (int i = 0; i < 15 - 1; i++)
      {
            for (int j = i; j < 15 - 1 - i; j++)
            {
                  if (a[j + 1] < a[j])
                        swap(&a[j + 1], &a[j]);
            }
      }
}
void insertion_sort(int a[])
{
      int j;
      for (int i = 0; i < 14; i++)
      {
            j = i - 1;
            int temp = a[i];
            while (j >= 0 && a[j] > temp)
            {
                  a[j + 1] = a[j];
                  j--;
            }
            a[j + 1] = temp;
      }
}
int main()
{
      int arr[15] = {1, 52, 556, 5, 265, 66, 4, 4, 6, 6, 656, 4, 11, 65, 46};
      insertion_sort(arr);
      print_arr(arr);
      return 0;
}