#include <iostream>
using namespace std;

int main()
{
    int n, n2, a = 0;
    cout << "Enter the number-->\n";
    cin >> n;
    n2 = n;
    while (n != 0)
    {
        a++;
        n /= 10;
    }
    int arr[a];
    for (int i = 0; i < a; i++)
    {
        arr[i] = n2 % 10;
        n2 /= 10;
    }
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a - i-1; j++)
        {
            arr[a - i - 1] *= 10;
        }
    }
    for (int i = 0; i < a; i++)
    {
        cout << arr[a - i - 1] << endl;
    }

    return 0;
}