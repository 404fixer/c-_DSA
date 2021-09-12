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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        int h, w;
        cin >> h >> w;

        int ans[h][w];
        mem0(ans);

        // making all corners 1 for maximum
        ans[0][0] = ans[0][w - 1] = ans[h - 1][0] = ans[h - 1][w - 1] = 1;

        // making first row
        int num = (int)ceil(w / 2.0);
        num -= 2;
        int i = 2;
        while (num--) {
            ans[0][i] = 1;
            i += 2;
        }

        // making last row as first row
        rep(j, 0, w) { ans[h - 1][j] = ans[0][j]; }

        // making first col
        num = (int)ceil(h / 2.0);
        // debug(num);
        num -= 2;
        i = 2;
        while (num--) {
            ans[i][0] = 1;
            i += 2;
        }

        // making last col as first col
        rep(j, 0, h) { ans[j][w - 1] = ans[j][0]; }

        rep(j, 0, h) {
            rep(k, 0, w) { cout << ans[j][k]; }
            cout << endl;
        }
        cout << endl;
    }
}