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
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll pos[k], temp[k];
        rep(i, 0, k) cin >> pos[i];
        map<ll, ll> ac;
        rep(i, 0, k) {
            ll temp;
            cin >> temp;
            ac.insert({pos[i], temp});
        }

        // for (auto &itr : ac) {
        //     debug(itr.fr);
        //     debug(itr.sc);
        // }

        vector<ll> from_r(n + 1, LLONG_MAX);
        bool te = true;
        for (int i = n - 1; i >= 0; i--) {
            if (ac.find(i + 1) != ac.end()) {
                if (te) {
                    from_r[i] = ac.find(i + 1)->sc;
                    te = false;
                } else
                    from_r[i] = min(from_r[i + 1] + 1, ac.find(i + 1)->sc);
            } else {
                if (from_r[i + 1] != LLONG_MAX) from_r[i] = from_r[i + 1] + 1;
            }
            // debug(i);
            // debug(from_r[i]);
        }

        vector<ll> from_l(n + 1, LLONG_MAX);
        te = true;
        rep(i, 0, n) {
            if (ac.find(i + 1) != ac.end()) {
                // debug(i);
                if (te) {
                    from_l[i] = ac.find(i + 1)->sc;
                    te = false;
                } else
                    from_l[i] = min(from_l[i - 1] + 1, ac.find(i + 1)->sc);
            } else {
                if (i == 0) continue;
                if (from_l[i - 1] != LLONG_MAX) from_l[i] = from_l[i - 1] + 1;
            }
        }

        rep(i, 0, n) {
            ll ans;
            // debug(from_l[i]);
            // debug(from_r[i]);
            ans = min(from_l[i], from_r[i]);
            cout << ans << " ";
        }
        cout << endl;
    }
}