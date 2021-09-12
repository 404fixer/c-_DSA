#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define mod 1000000009
#define debug(x) cout << #x << " " << x << endl;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll dp[100001][7];
    memset(dp, (ll)0, sizeof dp);
    for (int i = 2; i <= 100000; i++)
    {
        if (dp[i][1] == 0)
        {
            for (int j = i; j <= 100000; j += i)
            {
                // cout << i << " " << j << endl;
                int k = 6;
                while (dp[j][k] == 0 && k > 0)
                {
                    // dp[j][k] = dp[j - 1][k];
                    k--;
                }
                if (k != 7)
                    k++;

                dp[j][k] = dp[j - 1][k] + (ll)1;
                // debug(dp[j][k]);
            }
        }
        // else
        // {
        bool temp = true;
        for (int j = 6; j > 0; j--)
        {
            // if (i == 4)
            // {
            //     debug(j);
            //     debug(dp[i][j]);
            // }
            if (dp[i][j] != 0 && temp)
            {
                if (dp[i - 1][j] != 0)
                    dp[i][j]++;
                temp = false;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
        // }
    }

    // cout << dp[2][1] << endl;

    for (int i = 2; i <= 20; i++)
    {
        debug(i);
        for (int j = 1; j <= 6; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int a, b, k;
        cin >> a >> b >> k;

        debug(dp[a][k]);
        debug(dp[b][k]);
        ll ans;
        if (dp[a][k] != 0 && dp[b][k] != 0)
            ans = dp[b][k] - dp[a][k] + (ll)1;
        else
            ans = dp[b][k] - dp[a][k];

        cout << ans << endl;
    }
}