#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <climits>
#define endl "\n"
#define ll long long
#define MOD 1000000007
#define debug(x) cout << #x << " " << x << endl;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n >> x;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    vector<ll> dp(x + 1, 0);
    // ll dp[x + 1];
    dp[0] = 1;

    // for (int i = 1; i <= x; i++)
    // {
    //     dp[i] = 0;
    // }
    for (int i = 1; i < x + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j] > i)
            {
                break;
            }
            if (dp[i - arr[j]] == 0)
            {
                continue;
            }
            dp[i] += dp[i - arr[j]] % MOD;
        }
        // debug(dp[i]);
    }

    cout << dp[x] % MOD << endl;
}