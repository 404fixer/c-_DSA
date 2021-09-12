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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;

        if (a == b) cout << 0 << " " << 0 << endl;
        // else if (a == (ll)1 || b == (ll)1) {
        //     cout << abs(a - b) << " " << 0 << endl;}
        else {
            ll ans = abs(a - b);
            cout << ans << " ";
            if (ans == gcd(a, b)) {
                cout << 0 << endl;
            } else {
                // i've to see the nearest factor of ans
                ll temp = min(a, b) / ans;
                ll temp2 = min(a, b) % ans;
                ll temp3 = min(((temp + (ll)1) * ans) - min(a, b), temp2);
                cout << temp3 << endl;
            }
        }
    }
}