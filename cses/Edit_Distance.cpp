#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <cmath>
#include <string.h>
#include <algorithm>
#define endl "\n"
#define ll long long
#define mod 1000000007
#define debug(x) cout << #x << " " << x << endl;
using namespace std;

int dp[5001][5001];

int solve(int i, int j, string &s1, string &s2)
{
    if (i == (int)s1.length())
        return ((int)s2.length() - j);
    if (j == (int)s2.length())
        return ((int)s1.length() - i);

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans;
    if (s1[i] == s2[j])
    {
        ans = solve(i + 1, j + 1, s1, s2);
    }
    else
    {
        //insert
        int op1 = 1 + solve(i, j + 1, s1, s2);
        //delete
        int op2 = 1 + solve(i + 1, j, s1, s2);
        //replace
        int op3 = 1 + solve(i + 1, j + 1, s1, s2);

        ans = min(op1, min(op2, op3));
    }
    dp[i][j] = ans;

    return dp[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str, str2;
    cin >> str;
    cin >> str2;
    memset(dp, -1, sizeof(dp));

    int ans = solve(0, 0, str, str2);
    cout << ans << endl;
}