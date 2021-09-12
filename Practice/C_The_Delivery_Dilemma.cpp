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
#define deb(x) cout << #x << " " << x << endl;
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
        ll n;
        cin >> n;
        multimap<ll, ll> a;
        ll b[n];
        rep(i, 0, n) {
            ll temp;
            cin >> temp;
            a.insert({temp, i});
        }
        rep(i, 0, n) { cin >> b[i]; }

        ll self = 0;
        ll ans = (--a.end())->fr;
        while (!a.empty()) {
            auto itr = --a.end();
            ll big = itr->first;
            ll idx = itr->sc;

            // deb(self);
            // deb(ans);
            // deb(big);
            // deb(idx);
            // cout << "========" << endl;

            if (self + b[idx] < big) {
                self += b[idx];
                ans = max(self, big);
                a.erase(itr);
            } else {
                ans = max(self, big);
                break;
            }
        }

        if (a.empty()) ans = self;

        cout << ans << endl;
    }
}