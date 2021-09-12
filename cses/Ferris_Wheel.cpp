#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    long x;
    cin >> n >> x;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int l = 0, r = n - 1, ans = 0;
    while (l <= r)
    {
        ans++;
        if (arr[l] + arr[r] <= x)
        {
            l++;
        }
        r--;
    }

    cout << ans << "\n";
}