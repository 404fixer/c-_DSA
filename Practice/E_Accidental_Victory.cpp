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
#define pii pair<ll, int>
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
        vector<pii> v;
        v.pb({0, 0});
        rep(i, 1, n + 1) {
            ll x;
            cin >> x;
            v.pb({x, i});
        }

        sort(all(v));
        int mini = 0, maxi = 0;
        ll sum = 0;
        rep(i, 1, n + 1) {
            // debug(v[i].fr);
            // debug(v[i].sc);
            if (sum < v[i].fr) {
                mini = i;
                maxi = i;
                sum += v[i].fr;
                continue;
            }

            sum += v[i].fr;
            maxi++;
        }
        // debug(mini);
        // debug(maxi);
        cout << maxi - mini + 1 << endl;
        set<int> s;
        rep(i, mini, maxi + 1) { s.insert(v[i].sc); }
        for (auto &itr : s) cout << itr << " ";
        cout << endl;
    }
}