#include <iostream>
using namespace std;
int counter = 0;
void TowerofHanoi(int n, char source, char temp, char destination)
{
    if (n <= 0)
    {
        return;
    }
    else if (n > 0)
    {
        TowerofHanoi(n - 1, source, destination, temp);
        printf("Disk number %d moves from %c to %c\n", n, source, destination);
        counter++;
        TowerofHanoi(n - 1, temp, source, destination);
    }
}
int main()
{
    int n;
    cout << "Enter the number of disks -->" << endl;
    cin >> n;
    TowerofHanoi(n, 'A', 'B', 'C');
    cout << "The total number of moves required are " << counter << endl;
    return 0;
}