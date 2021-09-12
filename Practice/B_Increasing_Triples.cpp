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
    // cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        multiset<ll> a, b, c, d, e, f;
        rep(i, 0, 3) {
            rep(j, 0, n) {
                ll x;
                cin >> x;
                if (i == 0) a.insert(x);
                if (i == 1) b.insert(x);
                if (i == 2) c.insert(x);
            }
        }
        d = a, e = b, f = c;

        ll ans = 0, te1 = 0, te2 = 0;
        rep(i, 0, n) {
            auto itr = a.begin();
            if (b.upper_bound(*itr) == b.end()) {
                a.erase(itr);
                break;
            } else {
                auto itr2 = b.upper_bound(*itr);
                if (c.upper_bound(*itr2) == c.end()) {
                    a.erase(itr);
                    break;
                } else {
                    te1++;
                    auto itr3 = c.upper_bound(*itr2);
                    a.erase(itr);
                    b.erase(itr2);
                    c.erase(itr3);
                }
            }
        }

        rep(i, 0, n) {
            auto itr = --d.end();
            if (e.upper_bound(*itr) == e.end()) {
                d.erase(itr);
                // break;
            } else {
                auto itr2 = e.upper_bound(*itr);
                if (f.upper_bound(*itr2) == f.end()) {
                    d.erase(itr);
                    // break;
                } else {
                    te2++;
                    auto itr3 = f.upper_bound(*itr2);
                    d.erase(itr);
                    e.erase(itr2);
                    f.erase(itr3);
                }
            }
        }

        ans = max(te1, te2);
        cout << ans << endl;
    }
}