/* Program By govindtomariiit */

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define ld long double
#define int long long
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

long long C(int n, int r) {
    if (r > n - r) r = n - r;  // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for (i = 1; i <= r; i++) {
        ans = (ans * (n - r + i)) % mod;
        ans /= i;
    }

    return ans % mod;
}

ll po(ll x, ll n) {
    ll ans = 1;
    while (n > 0) {
        if (n & 1) ans = (ans * x) % mod;
        x = (x * x) % mod;
        n /= 2;
    }
    return ans;
}

#define N 200000
ll fac[N + 1], inv[N + 1];

void f() {
    fac[0] = inv[0] = 1;
    fac[1] = inv[1] = 1;
    for (int i = 2; i <= N; i++) {
        fac[i] = (fac[i - 1] * i) % mod;
        inv[i] = po(fac[i], mod - 2);
    }
}

ll nCr(ll a, ll b) {
    ll ans = fac[a];
    ans = (ans * inv[b]) % mod;
    ans = (ans * inv[a - b]) % mod;

    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a;
        rep(i, 0, n) {
            int temp;
            cin >> temp;
            a.pb(temp);
        }

        sort(all(a));
        int ans = 0;
        rep(i, 0, n - m + 1) {
            auto itr = upper_bound(all(a), a[i] + k);
            itr--;
            if (i != 0 && a[i] == a[i - 1]) continue;
            if (*itr <= a[i] + k) {
                // debug(itr - a.begin());
                // debug(*itr);
                int te = (itr - a.begin() + 1) - i;
                // debug(te);
                if (te >= m) {
                    // te -= (k - 1);
                    // if (te == m)
                    //     ans++;
                    // else
                    ans += (ans + nCr(te, te - m)) % mod;
                }
            }
            // debug(ans);
        }

        cout << ans % mod << endl;
    }
}