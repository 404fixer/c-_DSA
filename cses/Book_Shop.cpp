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

    int n, x;
    cin >> n >> x;

    int price[n + 1], pages[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> price[i];
    for (int i = 1; i <= n; i++)
        cin >> pages[i];

    int dp[n + 1][x + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int money = 0; money <= x; money++)
        {
            if (money == 0)
                dp[i][money] = 0;
            else if (money < price[i])
            {
                dp[i][money] = (i == 1) ? 0 : dp[i - 1][money];
            }
            else
            {
                int op1 = (i == 1) ? 0 : dp[i - 1][money];                              //when not considering ith book
                int op2 = (i == 1) ? pages[i] : pages[i] + dp[i - 1][money - price[i]]; // when taking ith book
                dp[i][money] = max(op1, op2);
            }
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int money = 0; money <= x; money++)
    //     {
    //         cout << dp[i][money] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[n][x] << endl;
}