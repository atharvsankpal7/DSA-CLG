/*
Name- Atharv Santosh Sankpal
URN - 21031040
Practical NO - 1
Practical Title - Recursion
*/
#include <stdio.h>
void towerOfHanoi(int n, char destination, char source, char helper)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoi(n - 1, destination, helper, source);
    printf("Move disk %d from rod %c to rod %c \n", n, destination, source);
    towerOfHanoi(n - 1, helper, source, destination);
}

int main()
{
    int N;
    printf("Enter the number of disks -->\n");
    scanf("%d", &N);
    towerOfHanoi(N, 'A', 'C', 'B');
    return 0;
}

