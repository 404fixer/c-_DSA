/* Program By govindtomariiit */

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

    int t = 1;
    // cin >> t;
    while (t--) {
        ll n, q, k;
        cin >> n >> q >> k;
        ll a[n];
        rep(i, 0, n) cin >> a[i];
        vector<pii> v;
        rep(i, 0, q) {
            int x, y;
            cin >> x >> y;
            v.pb({x, y});
        }
        ll dp[n];
        rep(i, 0, n) {
            if (i == n - 1) {
                dp[i] = dp[i - 1] + (k - a[i - 1] - 1);
                continue;
            }
            if (i == 0) {
                dp[i] = a[i + 1] - 2;
                continue;
            }
            dp[i] = dp[i - 1] + (a[i + 1] - a[i - 1] - 2);
        }

        // rep(i, 0, n) cout << dp[i] << " ";
        // cout << endl;

        rep(i, 0, q) {
            if (v[i].first == v[i].sc) {
                cout << k - 1 << endl;
            } else {
                ll num = v[i].sc - v[i].fr + 1;
                ll ans = dp[v[i].sc - 1];
                // debug(ans);
                // debug(num);
                if (v[i].fr != 1) {
                    ans -= (dp[v[i].fr - 2]);
                    // debug(ans);
                    ans += a[v[i].fr - 2];
                    // debug(ans);
                }
                if (v[i].sc != n) {
                    ans += k - a[v[i].sc] + 1;
                    // debug(ans);
                }
                cout << ans << endl;
            }
        }
    }
}