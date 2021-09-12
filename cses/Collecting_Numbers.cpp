#include <bits/stdc++.h>
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

    int nums[n + 1], ans = 0;
    for (int i = 0; i < n + 1; i++)
        nums[i] = 0;
    for (int i = 0; i < n; i++)
    {
        nums[arr[i]]++;

        if (nums[arr[i] - 1] == 0)
        {
            ans++;
        }
    }

    cout << ans << endl;
}