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
        string s;
        cin >> s;

        int ans1 = 11, ans2 = 11;
        int p = 0, q = 0, cnt = 5, cnt2 = 5;
        rep(i, 0, 10) {
            if (i % 2 == 0) {
                if (s[i] == '1' || s[i] == '?') p++;
                cnt--;
            } else {
                if (s[i] == '1') q++;
                cnt2--;
            }

            if (p > q + cnt2 || q > p + cnt) {
                ans1 = i + 1;
                break;
            }
        }

        p = 0, q = 0, cnt = 5, cnt2 = 5;
        rep(i, 0, 10) {
            if (i % 2 == 0) {
                if (s[i] == '1') p++;
                cnt--;
            } else {
                if (s[i] == '1' || s[i] == '?') q++;
                cnt2--;
            }

            if (q > p + cnt || p > q + cnt2) {
                ans2 = i + 1;
                break;
            }
        }

        // debugg(ans1, ans2);
        int ans = min(ans1, ans2);
        if (ans == 11) ans = 10;

        cout << ans << endl;
    }
}