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
        ll p, a, b, c;
        cin >> p >> a >> b >> c;

        ll ans;
        ll a_t = ceil((long double)p / a);
        ll b_t = ceil((long double)p / b);
        ll c_t = ceil((long double)p / c);

        ans = min((a * a_t) - p, min((b * b_t) - p, (c * c_t) - p));

        cout << ans << endl;
    }
}