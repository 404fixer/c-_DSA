#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define mod 1000000007
#define debug(x) cout << #x << " " << x << endl;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;

        ll arr[10];
        ll arr2[10];
        for (int i = 0; i < 10; i++) {
            arr[i] = (ll)0;
            arr2[i] = (ll)0;
        }

        int cnt = 9;
        while (l != 0 || r != 0) {
            arr[cnt] = l % (ll)10;
            arr2[cnt] = r % (ll)10;
            l = l / (ll)10;
            r = r / (ll)10;
            cnt--;
        }

        ll ans = 0;
        ll dp[10];
        for (int i = 0; i < 10; i++) {
            if (i == 0) {
                dp[i] = arr2[i] - arr[i];
            } else if (dp[i - 1] == 0) {
                dp[i] = arr2[i] - arr[i];
            } else {
                int op1 = arr2[i] == 0 ? 0 : arr2[i];
                int op2 = arr[i] == 0 ? 0 : 10 - arr[i];
                if (op1 == 0 && op2 == 0) {
                    op1 = 10;
                }
                dp[i] = (op1 + op2) + ((dp[i - 1] - 1) * 10);
                // dp[i] =
                //     dp[i - 1] + ((dp[i - 1]) * (op1 + op2) * pow(10, 10 -
                //     i));
            }
        }
        for (int i = 1; i < 10; i++) dp[i] += dp[i - 1];

        cout << dp[9] << endl;
    }
}