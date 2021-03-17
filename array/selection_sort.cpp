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

    for (int i = 0; i < n - 1; i++)
    {
        int minNumIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                minNumIndex = j;
            }
        }
        if (minNumIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minNumIndex];
            arr[minNumIndex] = temp;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}