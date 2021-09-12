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
        int n, k;
        cin >> n >> k;
        int a[k], b[k];
        vector<int> f(2 * n + 1, 1);
        int free = 2 * n;
        rep(i, 0, k) {
            cin >> a[i] >> b[i];
            free -= 2;
            f[a[i]] = 0, f[b[i]] = 0;
        }

        int ans = ((n - k) * (n - k - 1)) / 2;
        rep(i, 0, k) {
            int x = a[i], y = b[i];
            // Number of Intersection of all new chords with current given chord
            if (y < x) swap(x, y);
            int cnt = 0;
            rep(j, x + 1, y) if (f[j]) cnt++;
            ans += min(cnt, free - cnt);

            // Number of intersection of current old chord with all other old
            // chords
            rep(j, i + 1, k) {
                int u = a[j], v = b[j];
                if ((x < u && u < y) ^ (x < v && v < y)) ans++;
            }
        }

        cout << ans << endl;
    }
}