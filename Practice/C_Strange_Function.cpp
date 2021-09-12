/* Program By govindtomariiit */

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
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

ll mult(ll a, ll b) { return (a * b) % mod; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        ll tot = 0;
        ll count = n;
        ll mul = 1;
        for (ll i = 1; i <= 50; i++) {
            mul = (mul * i) / gcd(mul, i);
            tot = tot % mod + mult((count - n / mul), i);
            tot %= mod;
            count = n / mul;
            if (count == 0) break;
        }
        cout << tot;
        cout << endl;
    }
}