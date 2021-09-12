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

int n, e;
vector<int> v[100001];
vector<bool> vis(100001, false);

void dfs(int x) {
    vis[x] = true;

    for (auto y : v[x]) {
        if (!vis[y]) dfs(y);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin>>t;
    while (t--) {
        cin >> n >> e;

        rep(i, 0, e) {
            int a, b;
            cin >> a >> b;
            v[a].pb(b);
            v[b].pb(a);
        }

        int cc = 0;

        rep(i, 1, n + 1) {
            if (!vis[i]) dfs(i), cc++;
        }

        cout << cc << endl;
    }
}