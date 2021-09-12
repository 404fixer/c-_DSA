#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <climits>
#define endl "\n"
#define ll long long
#define mod 1000000007
#define debug(x) cout << #x << " " << x << endl;
using namespace std;

int dp[501][501];

int solve(int a, int b)
{
    if (a == b)
    {
        return 0;
    }
    if (dp[a][b] != -1)
    {
        return dp[a][b];
    }
    int ans = INT_MAX, temp = 0;
    for (int i = 1; i < a; i++)
    {
        temp = 1 + solve(i, b) + solve(a - i, b);
        ans = min(ans, temp);
    }
    for (int i = 1; i < b; i++)
    {
        temp = 1 + solve(a, i) + solve(a, b - i);
        ans = min(ans, temp);
    }
    dp[a][b] = ans;

    return dp[a][b];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin >> a >> b;

    memset(dp, -1, sizeof dp);
    int ans = solve(a, b);
    cout << ans << endl;
}