#include <stdio.h>
int main()
{
    int arr[4], max_e, curr_e, max_e_ind, NGE;
    printf("Enter the array --> \n");
    for (int i = 0; i < 4; i++)
    {
        printf("Enter the element number %d ", i + 1);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = i; j < 4; j++)
        {
            if (i == 4)
            {
                NGE = -1;
                break;
            }
            else if (arr[i] < arr[j])
            {
                NGE = arr[j];
                break;
            }
            else
            {
                NGE = -1;
            }
        }
        printf("The NGE of %d is %d \n", arr[i], NGE);
    }
    return 0;
}