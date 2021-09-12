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

    set<ll> arr;
    for (int i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        arr.insert(temp);
    }
    vector<ll> dp(x + 1, 0);
    dp[0] = 0;
    for (int i = 1; i < x + 1; i++)
    {
        ll temp = -1;
        for (auto itr : arr)
        {
            temp = -1;
            if (itr > i)
            {
                break;
            }
            if (dp[i - itr] == -1)
            {
                continue;
            }
            ll temp = dp[i - itr] + 1;
            if (dp[i] == 0)
                dp[i] = temp;
            dp[i] = min(temp, dp[i]);
        }
        if (dp[i] == 0)
            dp[i] = temp;
    }

    cout << dp[x] << endl;
}