#include <stdio.h>

int partition(int a[], int low, int high)
{
      int i, j, pivot, temp, temp1;

      pivot = a[low];
      i = low + 1;
      j = high;
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
                  temp = a[i];
                  a[i] = a[j];
                  a[j] = temp;
            }
      } while (i < j);

      temp = a[low];
      a[low] = a[j];
      a[j] = temp;

      return j;
}

void Quicksort(int a[], int low, int high)
{
      if (low < high)
      {
            int j = partition(a, low, high);
            Quicksort(a, low, j - 1);  // Solving Quicksort on LHS
            Quicksort(a, j + 1, high); // Solving Quicksort on RHS
      }
}

int main()
{
      int i, n;

      printf("\n Enter the size of array= ");
      scanf(" %d", &n);

      int a[n];
      for (i = 0; i < n; i++)
      {
            printf("\n Enter the data no.%d=", i + 1);
            scanf(" %d", &a[i]);
      }

      Quicksort(a, 0, n - 1);

      printf("\n Sorted List=");
      for (i = 0; i < n; i++)
      {
            printf("\t %d", a[i]);
      }
}