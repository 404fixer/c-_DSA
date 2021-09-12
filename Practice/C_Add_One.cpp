#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) (x).begin(), (x).end()
#define fr first
#define sc second
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define debug(x) cout << #x << " " << x << endl;
#define mod 1000000007
const long long inf = 1e18;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll dp[200005];
    mem0(dp);
    rep(i, 0, 200005) {
        if (i < 9)
            dp[i] = 2;
        else if (i == 9)
            dp[i] = 3;
        else {
            dp[i] = (dp[i - 9] + dp[i - 10]) % mod;
        }
    }

    int t = 1;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;

        ll ans = 0;
        while (n > 0) {
            int x = n % 10;
            ans += ((m + x < 10) ? 1 : dp[m + x - 10]);
            ans %= mod;
            n = n / 10;
        }

        cout << ans << endl;
    }
}