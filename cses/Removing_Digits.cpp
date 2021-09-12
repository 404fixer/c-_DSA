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

    vector<ll> dp(n + 1, 0);
    // dp[0] = 1;
    for (int i = 1; i < n + 1; i++)
    {
        set<int> digits;
        int temp = i;
        while (temp != 0)
        {
            digits.insert(temp % 10);
            temp /= 10;
        }

        for (auto itr : digits)
        {
            // debug(itr);
            if (dp[i] == 0)
                dp[i] = dp[i - itr];
            dp[i] = min(dp[i], dp[i - itr]);
        }
        dp[i]++;
        // debug(dp[i]);
    }

    cout << dp[n] << endl;
}