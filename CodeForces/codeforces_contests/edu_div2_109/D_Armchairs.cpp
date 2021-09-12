#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <cmath>
#define endl "\n"
#define ll long long
#define MOD 1000000007
#define debug(x) cout << #x << " " << x << endl;
using namespace std;

vector<int> ones;
vector<int> zero;
const int maxN = 5001;
ll dp[maxN][maxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            zero.push_back(i);
        else
            ones.push_back(i);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;

    if (ones.size() == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 1; i <= ones.size(); i++)
    {
        for (int j = 1; j <= zero.size(); j++)
        {
            ll temp = (ll)abs(ones[i] - zero[j]);
            dp[i][j] = min(temp, dp[i][j - 1]);
        }
    }

    // ll ans = helper(0, 0, zero.size(), ones.size());
    // cout << ans << endl;
}

// ll helper(0, 0)

// ans1 = helper[i][j+1]
// ans2 = helper[i+1][j+1] + abs(v2[i]-v1[j]);
// dp[i][j] = min(ans1, ans2);