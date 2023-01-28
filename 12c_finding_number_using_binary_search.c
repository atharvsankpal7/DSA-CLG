/*
Name- Atharv Santosh Sankpal
URN - 21031040
Practical NO - 9
Practical Title - Searching Techniques
*/
#include <stdio.h>
int main()
{
    printf("Welcome to the number guessing game!\n");
    printf("I will ask you to enter 'A' or 'B' to indicate if the number you are thinking of is present in the lower or upper half of the current range.\n");
    printf("Based on your input, I will narrow down the range until I determine the number.\n");
    int mid, low, high;
    char range;
    low = 0, high = 99;
    do
    {
        mid = (low + high) / 2;
        printf("Enter 'A' if the number is present between %d and %d\nEnter 'B' if the number is present between %d and %d -->\n", low, mid, mid + 1, high);
        scanf(" %c", &range);
        if (range == 'A')
        {
            high = mid;
        }
        else if (range == 'B')
        {
            low = mid + 1;
        }
    } while (low < high);
    printf("%d is your number\n", low);
    return 0;
}

