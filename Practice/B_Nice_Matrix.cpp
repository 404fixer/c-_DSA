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
#define ff first
#define ss second
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
        ll arr[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) cin >> arr[i][j];
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int a, b, c, d;
                a = i;
                b = n - 1 - i;
                c = j;
                d = m - 1 - j;
                pair<int, int> p1 = {a, c};
                pair<int, int> p2 = {a, d};
                pair<int, int> p3 = {b, c};
                pair<int, int> p4 = {b, d};
                // debug(p1.ff);
                // debug(p1.ss);
                set<pair<int, int>> s1;
                s1.insert(p1);
                s1.insert(p2);
                s1.insert(p3);
                s1.insert(p4);
                vector<ll> v1;
                for (auto k : s1) v1.pb(arr[k.ff][k.ss]);
                sort(v1.begin(), v1.end());
                int median = s1.size() / 2;
                ll a1 = v1[median];
                for (auto k : v1) ans += abs(k - a1);
                for (auto k : s1) arr[k.ff][k.ss] = a1;
            }
        }
        cout << ans << endl;
    }
}