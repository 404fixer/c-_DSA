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

    int arr[n + 1];
    for (int i = 1; i < n + 1; i++)
        cin >> arr[i];

    int dp[n + 1][x + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int sum = 0; sum <= x; sum++)
        {
            if (sum == 0)
            {
                dp[i][sum] = 1;
            }
            else
            {
                int op1 = (arr[i] > sum) ? 0 : dp[i][sum - arr[i]];
                int op2 = (i == 1) ? 0 : dp[i - 1][sum];
                dp[i][sum] = (op1 + op2) % MOD;
            }
        }
    }
    //2+3+5
    //5 + 5
    //2+2+2+2+2
    //3+3+2+2

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int sum = 0; sum <= x; sum++)
    //     {
    //         cout << dp[i][sum] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[n][x] << endl;
}