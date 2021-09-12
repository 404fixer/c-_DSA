/* Program By govindtomariiit */

#include <bits/stdc++.h>
#define endl "\n"
#define int long long
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
#define printyes cout << "YES" << endl;
#define printno cout << "NO" << endl;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;

        vector<ll> v;
        ll packet_sz = LLONG_MIN;
        rep(i, 1, sqrt(n) + 1) {
            if (n % i == 0) {
                // debug(i);
                if (n / i == i)
                    v.pb(i);
                else
                    v.pb(i), v.pb(n / i);
            }
        }

        sort(all(v));
        rep(i, 0, v.size()) {
            if (v[i] > k) break;
            packet_sz = v[i];
        }
        cout << n / packet_sz << endl;
    }
}