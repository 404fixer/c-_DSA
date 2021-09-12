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
        ll n, w;
        cin >> n >> w;
        multimap<ll, ll> ws;
        rep(i, 0, n) {
            ll temp;
            cin >> temp;
            ws.insert({temp, (ll)i});
        }

        ll lb = (ll)ceil((ld)w / 2);

        auto itr = ws.lower_bound(lb);
        if (itr != ws.end() && itr->first >= lb && itr->fr <= w) {
            cout << 1 << endl;
            cout << itr->sc + 1 << endl;
        } else {
            ll sum = 0;
            set<ll> idx;
            for (auto itr1 = ws.begin(); itr1 != itr; itr1++) {
                sum += itr1->fr;
                idx.insert(itr1->sc);
                if (sum >= lb) break;
            }

            if (sum >= lb && sum <= w) {
                cout << idx.size() << endl;
                for (auto &itr_idx : idx) {
                    cout << itr_idx + 1 << " ";
                }
                cout << endl;
            } else
                cout << -1 << endl;
        }
    }
}