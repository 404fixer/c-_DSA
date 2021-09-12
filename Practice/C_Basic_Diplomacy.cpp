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
        int n, m;
        cin >> n >> m;
        multiset<int> v[m];
        vector<pii> vv;
        rep(i, 0, m) {
            int x;
            cin >> x;
            rep(j, 0, x) {
                int temp;
                cin >> temp;
                v[i].insert(temp);
            }
            vv.pb({x, i});
        }

        sort(all(vv));
        vector<int> frnds(n + 1, 0);

        vector<int> days(m, 0);
        int maxi = (int)ceil((double)m / 2);

        rep(i, 0, m) {
            // debug(vv[i].fr);
            // debug(vv[i].sc);
            for (auto &itr : v[vv[i].sc]) {
                // cout << itr << " ";
                // debug(frnds[itr]);
                // debug(maxi);
                if (frnds[itr] < maxi) {
                    days[vv[i].sc] = itr;
                    // debug(days[vv[i].sc]);
                    frnds[itr]++;
                    // debug(frnds[itr]);
                    break;
                }
            }
            // cout << endl;
        }

        bool ans = true;
        rep(i, 0, m) {
            // debug(i);
            // debug(days[i]);
            if (days[i] == 0) {
                ans = false;
                break;
            }
        }

        if (!ans)
            cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            rep(i, 0, m) { cout << days[i] << " "; }
            cout << endl;
        }
    }
}