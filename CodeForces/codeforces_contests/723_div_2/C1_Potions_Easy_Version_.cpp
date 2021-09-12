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

    int n;
    cin >> n;

    ll arr[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    ll dp[n + 1][n + 1];
    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] =
        }
    }
}