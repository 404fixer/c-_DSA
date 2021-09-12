/* Program By govindtomariiit */

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define ld long double
#define int long long
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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        int arr[n];
        rep(i, 0, n) cin >> arr[i];

        vector<int> v;
        if (n == 1) v.pb(arr[0]);
        bool posi = true;
        rep(i, 1, n) {
            if (posi) {
                if (arr[i] <= arr[i - 1])
                    v.pb(arr[i - 1]), posi = false;
                else if (i == n - 1)
                    v.pb(arr[i]), posi = false;
            } else {
                if (arr[i] >= arr[i - 1]) {
                    v.pb(arr[i - 1]), posi = true;
                    if (i == n - 1) i--;
                }
            }
        }

        int ans = 0;
        rep(i, 0, v.size()) {
            if (i % 2 == 0) {
                ans += v[i];
            } else
                ans -= v[i];
        }
        cout << ans << endl;
    }
}