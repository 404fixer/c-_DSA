/* Program By govindtomariiit */

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define ld long double
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
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll x[n];
        rep(i, 0, n) cin >> x[i];

        vector<ll> y;
        y.pb(0);
        rep(i, 1, n) {
            ll prev = x[i - 1] ^ y[y.size() - 1];
            ll curr = 0;
            rep(j, 0, 30) {
                if (prev & (1 << j)) {
                    if (x[i] & (1ll << j)) {
                        // do nothing
                    } else {
                        curr = curr | (1ll << j);
                    }
                }
            }
            y.pb(curr);
        }

        rep(i, 0, n) cout << y[i] << " ";
        cout << endl;
    }
}