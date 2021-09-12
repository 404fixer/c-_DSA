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
        int n;
        cin >> n;
        int arr[n];
        rep(i, 0, n) cin >> arr[i];

        vector<int> v;
        int prev = arr[0];
        v.pb(arr[0]);
        rep(i, 0, n) {
            if (arr[i] != prev) {
                v.pb(arr[i]);
            }
            prev = arr[i];
        }

        map<int, int> m;
        rep(i, 0, v.size()) { m[v[i]]++; }

        int ans = INT_MAX;
        for (auto &itr : m) {
            // debug(itr.fr);
            // debug(itr.sc);
            // debug(ans);
            if (itr.fr == v[0] && v[0] == v[v.size() - 1]) {
                ans = min(ans, itr.sc - 1);
            } else if (itr.fr == v[0] || itr.fr == v[v.size() - 1]) {
                ans = min(ans, itr.sc);
            } else {
                ans = min(ans, itr.sc + 1);
            }
        }

        cout << ans << endl;
    }
}