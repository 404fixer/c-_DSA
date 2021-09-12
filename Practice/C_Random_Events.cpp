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
#define rep1(i, a, b) for (int i = a; i >= b; i--)
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define debug(x) cout << #x << " " << x << endl;
#define mod 1000000007
const long long inf = 1e18;
using namespace std;

ll gcd(ll a, ll b) {
    if (b > a) {
        return gcd(b, a);
    }
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
ll expo(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
void google(ll t) { cout << "Case #" << t << ": "; }
#define printyes cout << "YES" << endl
#define printno cout << "NO" << endl

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[n + 1];
        rep(i, 1, n + 1) cin >> arr[i];
        vector<pair<int, double>> v(m);
        rep(i, 0, m) {
            int x;
            double y;
            cin >> x >> y;
            v[i].fr = x;
            v[i].sc = y;
            // k v.pb({x, y});
            // debug(v[i].fr);
        }

        int idx = -1;
        rep1(i, n, 1) {
            if (arr[i] != i) {
                idx = i;
                break;
            }
        }

        // debug(idx);
        double ans;
        if (idx == -1) {
            ans = 0.000000;
        } else {
            ans = 1.000000;
            int cnt = 0;
            rep(i, 0, m) {
                // debug(v[i].fr);
                if (v[i].fr >= idx) {
                    // debug(ans);
                    if (cnt == 0) {
                        // ans = v[i].sc;
                        ans = 1 - v[i].sc;
                        cnt++;
                        continue;
                    }
                    ans *= (1 - v[i].sc);
                }
            }
        }

        cout << fixed << showpoint;
        cout << setprecision(6);
        cout << 1 - ans << endl;
    }
}