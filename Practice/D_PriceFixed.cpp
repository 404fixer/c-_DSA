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
    // cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        multimap<ll, ll, greater<ll>> m;
        rep(i, 0, n) {
            ll x, y;
            cin >> x >> y;
            m.insert({y, x});
        }

        ll pur = 0;
        ll ans = 0;

        while (!m.empty()) {
            auto itr = m.begin();
            auto itr2 = --m.end();

            // 6 1
            // 2 1
            // 2 2
            // 1 4

            // debug(ans);
            // debug(pur);

            if (pur >= itr2->fr) {
                // cout << "a" << endl;
                pur += itr2->sc;
                ans += itr2->sc;
                m.erase(itr2);
            } else {
                if (pur + itr->sc <= itr2->fr) {
                    // cout << "b" << endl;
                    pur += itr->sc;
                    ans += 2 * itr->sc;
                    m.erase(itr);
                } else {
                    // cout << "c" << endl;
                    ans += 2 * (itr2->fr - pur);
                    itr->sc -= (itr2->fr - pur);
                    pur = itr2->fr;
                    ans += itr2->sc;
                    pur += itr2->sc;
                    m.erase(itr2);
                }
            }

            // debug(ans);
            // debug(pur);
            // cout << "==============" << endl;
        }

        cout << ans << endl;
    }
}