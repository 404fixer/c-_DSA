#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int mid, base;
    if (n % 2 != 0)
    {
        mid = (n + 1) / 2;
        base = arr[mid - 1];
    }
    else
    {
        mid = n / 2;
        base = (arr[mid - 1] + arr[mid]) / 2;
    }

    long long cost = 0;
    for (int i = 0; i < n; i++)
    {
        cost += abs(arr[i] - base);
    }

    cout << cost << endl;
}