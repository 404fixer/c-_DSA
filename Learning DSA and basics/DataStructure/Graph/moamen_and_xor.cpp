// if n is even then, number of set bits should also be even at kth position out
// of n numbers if n is odd then, number of set bits should also be even at kth
// position out of n numbers

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
#define pyn(flag) cout << (flag ? "YES" : "NO") << endl;

const int N = 1e5 + 1;

ll ncr(ll n, ll r) {
    if (r > n - r) r = n - r;  // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for (i = 1; i <= r; i++) {
        ans = ans * (n - r + i);
        ans %= mod;
        ans /= i;
        ans %= mod;
    }

    return ans;
}

ll findX(ll n) {
    ll te = 0;
    for (int i = 0; i <= ((n % 2 == 0) ? (n - 2) : (n - 1)); i += 2) {
        te += ncr(n, (ll)i);
        te %= mod;
    }

    return te;
}

ll solve(ll n, ll k, ll x) {
    ll ans = 0;

    if (k == 0) return 1;

    if (n % 2 == 0) {
        ans = expo(expo(2, k - 1), n) + (x * solve(n, k - 1, x));
        ans %= mod;
    } else {
        ans = (solve(n, k - 1, x)) * (x + 1);
        ans %= mod;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;

        ll x = findX(n);

        debug(x);
        cout << solve(n, k, x) << endl;
    }
}