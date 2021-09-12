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
#define vi vector<int>
#define mii map<int, int>
#define mci map<char, int>
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
        ll n, x, y, k;
        cin >> n >> x >> y >> k;

        ll c[n];
        rep(i, 0, n) cin >> c[i];
        map<ll, ll> m;
        rep(i, 0, n) { m[c[i]]++; }

        ll te = x;
        while (m.find(te) != m.end()) {
            te++;
        }
        rep(i, 0, n) {
            if (m[c[i]] > 1) {
                while (m.find(te) != m.end()) {
                    te++;
                }
                if (m.find(te) == m.end() && te <= y && k > 0) {
                    m.insert({te, 1});
                    k--;
                }
            }
        }

        // set<ll> s;
        // ll te = x;
        // rep(i, 0, n) {
        //     if (s.find(c[i]) == s.end()) {
        //         s.insert(c[i]);
        //         if (c[i] == te) te++;
        //     } else {
        //         while (s.find(te) != s.end() && te <= y) {
        //             te++;
        //         }
        //         if (te <= y && k > 0) {
        //             s.insert(te);
        //             k--;
        //             te++;
        //         }
        //     }
        // }

        cout << m.size() << endl;
    }
}