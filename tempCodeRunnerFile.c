/*
Roll No. :- 2029.
URN No. :- 21031065.
Batch:-S2
Name:- Om Sambhaji Sawant.

Practical No.10 :- Program to develop computer game for guessing number between 1-100*/

#include <stdio.h>
int main()
{
      int mid, low, high;
      char choice;
      low = 0, high = 100;
      printf("\nChoose one number between 1 to 100\n");
      do
      {
            mid = (low + high) / 2;
            printf("\nIf the number is present between %d and %d Press 'A'\nIf the number is present between %d and %d Press 'B'\n", low, mid, mid + 1, high);
            scanf(" %c", &choice);
            if (choice == 'A')
            {
                  high = mid;
            }
            else if (choice == 'B')
            {
                  low = mid + 1;
            }
      } while (low < high);
      printf("\n%d is your number\n", low);
      return 0;
}