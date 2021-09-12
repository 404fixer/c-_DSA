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

// ll fact(ll n) {
//     if (n <= 1) return (ll)1;
//     return (n * fact(n - 1)) % mod;
// }

// ll nPr(ll n, ll r) { return (fact(n) / fact(n - r)) % mod; }

// ll fast_pow(ll a, ll p) {
//     ll res = 1;
//     while (p) {
//         if (p % 2 == (ll)0) {
//             a = a * 1ll * a % mod;
//             p /= (ll)2;
//         } else {
//             res = res * 1ll * a % mod;
//             p--;
//         }
//     }
//     return res % mod;
// }

// ll fact(ll n) {
//     ll res = (ll)1;
//     for (ll i = 1; i <= n; i++) {
//         res = res * 1ll * i % mod;
//     }
//     return res % mod;
// }

// ll C(ll n, ll k) {
//     return fact(n) * 1ll * fast_pow(fact(k), mod - 2) % mod * 1ll *
//            fast_pow(fact(n - k), mod - 2) % mod;
// }

ll factorialDivision(ll topFactorial, ll divisorFactorial) {
    ll result = 1;
    ll i;
    for (i = topFactorial; i > divisorFactorial; i--) result *= i;
    return result;
}

ll factorial(ll i) {
    if (i <= 1) return 1;
    return i * factorial(i - 1);
}

ll nPr(ll n, ll r) {
    // naive: return factorial(n) / factorial(n - r);
    return factorialDivision(n, n - r);
}

ll nCr(ll n, ll r) {
    // naive: return factorial(n) / factorial(r) * factorial(n - r);
    return nPr(n, r) / factorial(r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin>>t;
    while (t--) {
        ll n;
        cin >> n;
        map<ll, ll> m;
        rep(i, 0, n) {
            ll temp;
            cin >> temp;
            m[temp]++;
        }

        // ll big = (--m.end())->fr;
        ll ans = 0;
        ll used = 0;
        int cnt = 0;
        for (auto &itr : m) {
            // debug(used);
            // debug(ans);
            if (itr.fr < itr.sc || itr.fr - used < itr.sc) {
                // cout << "here" << endl;
                ans = 0;
                break;
            } else {
                // cout << "else here" << endl;
                if (cnt == 0) {
                    ans = (nPr(itr.fr - used, itr.sc)) % mod;
                    used += itr.sc;
                    cnt++;
                    continue;
                }

                ans *= (nPr(itr.fr - used, itr.sc)) % mod;
                ans %= mod;

                used += itr.sc;
                // big -= itr.sc;
            }
            // debug(used);
            // debug(ans);
            // cout << "==============\n";
        }

        cout << ans << endl;
    }
}