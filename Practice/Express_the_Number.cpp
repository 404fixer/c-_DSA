/* Program By govindtomariiit */

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define int ll
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
#define pyn(flag) cout << (flag ? "YES" : "NO") << endl;

const int N = 1e5 + 1;
set<ll> st;
ll k = 0;

// 10100

void solve(ll n, int x) {
    if (n <= x) {
        k++;
    }

    ll ans = 0, temp = 0, even = 0;
    ll shivam = x;
    rep(i, 0, 31) {
        if (i % 2 == 0) {
            if (((1 << i) & n) != 0) {
                // this bit is one
                if ((1 << i) <= x) {
                    x -= (1 << i);
                } else {
                    even += 2;
                }
            }
        } else {
            if (((1 << i) & n) != 0) {
                // debug(i);
                k++;
                temp++;
            }
        }
    }

    if (shivam != x) {
        k++;
    }

    cout << k + even << endl;

    // if (ans == 0)
    //     return true;
    // else if (ans <= x) {
    //     k++;
    //     return true;
    // } else {
    //     return (k + even);
    // }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // rep(i, 0, 31) {
    //     if (i % 2 == 1) {
    //         st.insert(expo(2, i));
    //     }
    // }

    int t = 1;
    cin >> t;
    while (t--) {
        ll n, x;
        cin >> n >> x;

        k = 0;

        // while (n > 1) {
        //     if (n <= x) {
        //         k++;
        //         break;
        //     }
        //     auto itr = st.lower_bound(n);
        //     if (*itr > n && itr != st.begin()) itr--;
        //     ll temp = n / (*itr);
        //     k += temp;
        //     n -= temp * (*itr);
        //     if (n != 0 && n < x) {
        //     }
        //     // n -= *itr;
        // }

        // if (n == 1) {
        //     if (x >= n)
        //         cout << k + 1 << endl;
        //     else
        //         cout << -1 << endl;
        // } else
        //     cout << k << endl;

        if (n % 2 == 1 && x == 0) {
            cout << -1 << endl;
            continue;
        }

        k = 0;
        solve(n, x);
        // if (solve(n, x))
        //     cout << k << endl;
        // else
        //     cout << -1 << endl;
    }
}