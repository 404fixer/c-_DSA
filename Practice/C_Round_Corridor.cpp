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
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define debug(x) cout << #x << " " << x << endl;
#define mod 1000000007
const long long inf = 1e18;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin>>t;
    while (t--) {
        ll n, m, q;
        cin >> n >> m >> q;

        ll g = gcd(n, m);
        ll gp_sz_n = n / g;
        ll gp_sz_m = m / g;

        while (q--) {
            ll a, b, c, d;
            cin >> a >> b >> c >> d;

            ll te1 = (ll)ceil((ld)b / (a == 1 ? gp_sz_n : gp_sz_m));
            ll te2 = (ll)ceil((ld)d / (c == 2 ? gp_sz_m : gp_sz_n));

            if (te1 == te2)
                cout << "YES" << endl;
            else
                cout << "NO\n";
        }
    }
}