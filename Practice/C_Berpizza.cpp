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
    // cin >> t;
    while (t--) {
        int q;
        cin >> q;
        int val[5 * 100005];

        set<int> customer_id;
        set<pair<int, int>> customer_valueid;
        int id = 1;
        for (int i = 0; i < q; ++i) {
            int ty;
            cin >> ty;
            if (ty == 1) {
                int m;
                cin >> m;
                val[id] = m;
                customer_valueid.insert({-m, id});
                customer_id.insert(id);
                id++;
            } else if (ty == 2) {
                int sid = *customer_id.begin();
                customer_id.erase(sid);
                customer_valueid.erase({-val[sid], sid});
                cout << sid << " ";
            } else {
                int sid = customer_valueid.begin()->sc;
                customer_valueid.erase(customer_valueid.begin());
                customer_id.erase(sid);
                cout << sid << " ";
            }
        }
    }
}