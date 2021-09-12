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
#define debugg(x, y) cout << #x " " << x << " " << #y << " " << y << endl;
#define setPre(x)               \
    cout << fixed << showpoint; \
    cout << setprecision(x);
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
#define py cout << "YES" << endl
#define pn cout << "NO" << endl

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
        map<ll, ll> m;
        rep(i, 0, n) {
            cin >> a[i];
            m[a[i]]++;
        }

        ll ans = 0;
        ll te = (m.begin())->first;
        ll cnt = 0;

        if (m.size() == 1) {
            ans = 0;
            cout << ans << endl;
            continue;
        }

        if (te == 0) {
            cnt = -1;
            ans = n - (m.begin()->sc);
        }

        if (te != 1 && te != 0) {
            for (auto &itr : m) {
                if (cnt == 0) {
                    cnt++;
                    continue;
                }
                if (itr.fr % te == 0) {
                    cnt = -1;
                    ans = n;
                    break;
                }
            }
        }

        if (cnt != -1) {
            auto itr = m.begin();
            ll temp = itr->fr;
            if (m.size() > 1) {
                itr++;
                ll temp2 = itr->fr;

                if (temp2 - temp != 1) {
                    if ((temp2) % (temp2 - temp) == temp) {
                        itr--;
                        ans = n - itr->sc;
                    } else {
                        ans = n;
                    }

                } else {
                    ans = n;
                }
            } else {
                ans = 0;
            }
        }

        cout << ans << endl;
    }
}