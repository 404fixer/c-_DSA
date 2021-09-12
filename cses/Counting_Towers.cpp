#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <cmath>
#include <string>
#include <algorithm>
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

        ll dp[n + 2][2];

        dp[1][0] = dp[1][1] = (ll)1;
        for (int i = 2; i <= n; i++)
        {
            //dp[i][0] means number of buildings of height i, with two tiles on top floor with each of width 1
            //dp[i][1] means number of buildings of height i, with one tile on top floor with width 2

            // i-1 th tiles does not extend and i-1 th tiles are of width 1
            ll op1 = (dp[i - 1][1] + dp[i - 1][0]) % mod;
            // extend both
            ll op2 = dp[i - 1][0];
            //extend one of these
            ll op3 = (2 * dp[i - 1][0]) % mod;
            // extend i-1 th tile when width == 2
            ll op4 = dp[i - 1][1];

            dp[i][0] = (op1 + op2 + op3) % mod;
            dp[i][1] = (op1 + op4) % mod;

            // if (i == n)
            // {
            debug(i);
            debug(op1);
            debug(op2);
            debug(op3);
            debug(op4);
            debug(dp[i][0]);
            debug(dp[i][1]);
            cout << "==================" << endl;

            // }
        }

        // for (int i = 1; i <= n; i++)
        cout << (dp[n][0] + dp[n][1]) % mod << endl;
    }
}