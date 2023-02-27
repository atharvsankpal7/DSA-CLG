#include <stdio.h>
int toh(int n, char source, char destination, char aux)
{
    if (n > 0)
    {
        toh(n - 1, source, aux, destination);
        printf("The ring %d is moved from %c to %c \n", n, source, destination);
        toh(n - 1, aux, source, destination);
    }
}
int main()
{
    toh(4, 'A', 'B', 'C');
    return 0;
}