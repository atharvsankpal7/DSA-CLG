/*
Name- Atharv Santosh Sankpal
URN - 21031040
Practical NO - 9
Practical Title - Searching Techniques
*/
#include <stdio.h>
int main()
{
    int a[10] = {56, 15, 4, 1, 6463, 15, 64, 6, 56, 21};
    int key, flag = 0, i;
    printf("Enter the element that you want to search --> ");
    scanf("%d", &key);
    for (i = 0; i < 10; i++)
    {
        if (a[i] == key)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        printf("Element found at %d position", i + 1);
    }
    else
    {
        printf("Element not found");
    }
    return 0;
}