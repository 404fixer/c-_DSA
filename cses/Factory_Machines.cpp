#include <iostream>
#define endl "\n"
using namespace std;

bool check(long long mid, int arr[], int k, int n)
{
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += min(mid / arr[i], (long long)1e9);
    }

    return (sum >= k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long l = 0, r = 1e18;
    while (l < r)
    {
        long long mid = l + (r - l) / 2;
        if (check(mid, arr, k, n))
            r = mid;
        else
            l = mid + 1;
    }

    cout << l << endl;
}