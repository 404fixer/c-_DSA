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

    int n, q;
    cin >> n >> q;
    string str;
    cin >> str;
    int l[q], r[q];
    for (int i = 0; i < q; i++) {
        cin >> l[i] >> r[i];
    }

    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + (str[i - 1] - 96);
    }

    for (int i = 0; i < q; i++) {
        // debug(dp[r[i]]);
        // debug(dp[l[i]]);
        cout << dp[r[i]] - dp[l[i] - 1] << endl;
    }
}