#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> houses(n);
        for (int i = 0; i < n; i++)
            cin >> houses[i];

        sort(houses.begin(), houses.end());
        int mid = houses[n / 2];
        long long arr[2];
        arr[0] = 0;
        arr[1] = 0;
        long long ans;
        for (int j = 0; j < 2; j++)
        {
            int left = (k - 1) / 2;
            int right = (k - 1 - left);

            if (j == 1)
                swap(left, right);

            left = mid - left;
            right = mid + right;

            for (int i = 0; i < n; i++)
            {
                arr[j] += (long long)max(abs(houses[i] - left), abs(houses[i] - right));
            }

            ans = min(arr[0], arr[1]);
        }

        cout << ans << endl;
    }
}