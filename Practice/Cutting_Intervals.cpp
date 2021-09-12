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
    cin >> t;
    ll cnt = 1;
    while (t--) {
        ll n, c;
        cin >> n >> c;
        ll b[n][2];
        rep(i, 0, n) { cin >> b[i][0] >> b[i][1]; }

        ll ans = 0;
        rep(i, 0, n) {
            if (b[i][0] + 1 == b[i][1]) {
                continue;
            }
            ans += b[i][1] - b[i][0];
        }

        cout << "Case #" << cnt << ": " << ans << endl;
        cnt++;
    }
}