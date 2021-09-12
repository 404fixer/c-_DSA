#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <cstring>
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

    int n, m;
    cin >> n >> m;

    int arr[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    int dp[n + 2][m + 2];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int value = 1; value <= m; value++)
        {
            if (i == 1)
            {
                if (arr[i] == 0 || arr[i] == value)
                    dp[i][value] = 1;
                else
                    dp[i][value] = 0;
            }
            else
            {
                if (arr[i] == 0 || arr[i] == value)
                    dp[i][value] = ((dp[i - 1][value - 1] + dp[i - 1][value]) % MOD + dp[i - 1][value + 1]) % MOD;
                else
                    dp[i][value] = 0;
            }
        }
    }

    ll ans = 0;
    for (int value = 1; value <= m; value++)
    {
        ans = (ans + (ll)dp[n][value]) % MOD;
    }

    cout << ans << endl;
}