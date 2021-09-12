#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define mod 1000000009
#define debug(x) cout << #x << " " << x << endl;
using namespace std;

ll dp[1000002];
// ll countNum;

ll solve(int x)
{
    // countNum++;
    // countNum %= mod;
    if (x < 0)
        return (ll)0;

    if (dp[x] != (ll)-1)
        return dp[x];

    return dp[x] = (solve(x - 3) + solve(x - 2)) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;

        for (int i = 0; i <= x; i++)
            dp[i] = (ll)-1;

        dp[0] = (ll)1;
        // countNum = 0;
        cout << solve(x) % mod << endl;
        // cout << countNum << endl;
    }
}