/* Program By govindtomariiit */

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define int long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        int x, y, n, k;
        cin >> n >> k;
        int a[n], b[n];
        map<int, int> u;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % k) {
                b[i] = (k - a[i] % k);
            } else
                b[i] = 0;
        }
        x = n;

        sort(b, b + n);

        int c = 1;
        for (int i = 0; i < n; i++) {
            if (b[i] > 0) {
                u[b[i]] += 1;
            }
        }
        int sum = 0;
        for (auto x : u) {
            if (x.ss > 1) {
                y = 1;
                for (int i = 1; i < x.ss; i++) {
                    while (1) {
                        if (u[x.ff + y * k] == 0) {
                            u[x.ff + y * k] = 1;
                            y++;
                            break;
                        } else
                            y++;
                    }
                }
            }
            if (c == u.size()) sum = x.ff;
            c++;
        }
        if (sum != 0) sum++;
        cout << sum << endl;
    }
}