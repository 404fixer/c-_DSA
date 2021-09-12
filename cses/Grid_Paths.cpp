#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
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

    int n;
    cin >> n;

    char grid[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    ll dp[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '*')
            {
                dp[i][j] = (ll)0;
            }
            else if (i == 0 && j == 0)
            {
                dp[i][j] = (ll)1;
            }
            else if (i == 0)
            {
                dp[i][j] = dp[i][j - 1];
            }
            else if (j == 0)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]);

            dp[i][j] %= MOD;
        }
    }

    cout << dp[n - 1][n - 1] << endl;
}