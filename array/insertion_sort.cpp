#include <iostream>
using namespace std;

int main()
{
    int n, j;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        for (j = i - 1; arr[j] > current && j >= 0; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = current;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
}