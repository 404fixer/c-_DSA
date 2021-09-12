#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define mod 1000000007
#define debug(x) cout << #x << " " << x << endl;
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
        int n;
        cin >> n;
        ll arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        // ll ans = (ll)n;
        ll dp[n];
        dp[0] = (ll)n;
        ll temp = (ll)0;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] >= arr[i - 1])
            {
                temp++;
                dp[i] = dp[i - 1] + temp;
                //1 2 3 4 5
            }
            else
            {
                dp[i] = dp[i - 1];
                temp = (ll)0;
            }
        }

        cout << dp[n - 1] << endl;
    }
}