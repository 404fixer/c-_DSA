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

    int t;
    cin >> t;
    while (t--)
    {
        int q, d;
        cin >> q >> d;
        ll arr[q];
        for (int i = 0; i < q; i++)
            cin >> arr[i];

        vector<bool> dp(10 * d, false);
        dp[0] = true;
        for (int i = 1; i < 10 * d; i++)
        {
            for (int j = d; j <= i; j += 10)
            {
                if (dp[i - j])
                    dp[i] = true;
            }
        }

        for (int i = 0; i < q; i++)
        {
            if (arr[i] >= (ll)(10 * d))
                cout << "YES" << endl;
            else if (dp[arr[i]])
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
}