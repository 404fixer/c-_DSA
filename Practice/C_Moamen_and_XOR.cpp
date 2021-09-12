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
#define MOD 1000000007
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
ll expo(ll a, ll b, ll mod) {
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

ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }

ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {
    ll val1 = fact[n];
    ll val2 = ifact[n - r];
    ll val3 = ifact[r];
    return (((val1 * val2) % m) * val3) % m;
}

ll mod_add(ll a, ll b, ll m) {
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m) {
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m) {
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m) {
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}  // only for prime m

ll solve(ll n, ll k, ll x) {
    ll ans = 0;

    if (k == 0) return 1;

    if (n % 2 == 0) {
        ans = expo(expo(2, k - 1, MOD), n, MOD) + (x * solve(n, k - 1, x));
        ans %= MOD;
    } else {
        ans = (solve(n, k - 1, x)) * (x + 1);
        ans %= MOD;
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

        ll *fact = new ll[n + 1];
        ll *ifact = new ll[n + 1];
        fact[0] = 1, ifact[0] = 1;
        for (ll i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
            ifact[i] = mminvprime(fact[i], MOD);
        }
        ll x = 0;
        for (ll i = 0; i <= ((n % 2 == 0) ? (n - 2) : (n - 1)); i += 2) {
            ll y = combination(n, i, MOD, fact, ifact);
            x = mod_add(y, x, MOD);
        }
        // debug(x);

        cout << solve(n, k, x) << endl;
    }
}