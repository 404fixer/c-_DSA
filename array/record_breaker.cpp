#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int max = -1;
    int days = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max && (arr[i] > arr[i + 1] || i == n - 1))
        {
            max = arr[i];
            days++;
        }
    }

    cout << days << endl;
}