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
        int n;
        cin >> n;

        string str;
        cin >> str;

        string te1, te2;
        rep(i, 0, n) {
            if (i % 2 == 0) {
                te1.pb('1');
                te2.pb('0');
            } else {
                te1.pb('0');
                te2.pb('1');
            }
        }

        int o = 0, z = 0;
        int cnt = 0;
        rep(i, 0, n - 1) {
            if (str[i] == str[i + 1] && str[i] == '1') {
                // debug(i);
                cnt++;
            } else {
                if (cnt != 0) {
                    o += (cnt);
                    cnt = 0;
                }
            }
        }

        cnt = 0;
        rep(i, 0, n - 1) {
            if (str[i] == str[i + 1] && str[i] == '0') {
                // debug(i);
                cnt++;
            } else {
                if (cnt != 0) {
                    z += (cnt);
                    cnt = 0;
                }
            }
        }

        // if (str[n - 1] == '1') o++;
        cnt = max(o, z);

        if (str == te1 || str == te2) o = 0;

        cout << cnt << endl;
    }
}