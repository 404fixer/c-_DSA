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

bool check(ll p, ll q, ll r) {
    if ((p <= q && q <= r) || (p >= q && q >= r)) return true;

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll a[n];
        rep(i, 0, n) cin >> a[i];

        ll ans = n + (n - 1);
        rep(i, 0, n - 2) {
            if ((a[i] <= a[i + 1] && a[i + 1] <= a[i + 2]) ||
                (a[i] >= a[i + 1] && a[i + 1] >= a[i + 2])) {
                // do nothing
            } else {
                ans++;
            }
        }

        rep(i, 0, n - 3) {
            ll p = a[i], q = a[i + 1], r = a[i + 2], s = a[i + 3];

            if (check(p, q, r) || check(p, q, s) || check(q, r, s) ||
                check(p, r, s)) {
            } else
                ans++;
        }

        cout << ans << endl;
    }
}