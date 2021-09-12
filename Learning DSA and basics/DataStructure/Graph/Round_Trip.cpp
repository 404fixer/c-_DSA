// check whether cyclic or not and print the order
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
#define rep1(i, a, b) for (int i = a; i >= b; i--)
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define debug(x) cout << #x << " " << x << endl;
#define debugg(x, y) cout << #x " " << x << " " << #y << " " << y << endl;
#define setPre(x)               \
    cout << fixed << showpoint; \
    cout << setprecision(x);
#define mod 1000000007
const long long inf = 1e18;
using namespace std;

ll gcd(ll a, ll b) {
    if (b > a) {
        return gcd(b, a);
    }
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
ll expo(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
void google(ll t) { cout << "Case #" << t << ": "; }
#define py cout << "YES" << endl
#define pn cout << "NO" << endl

const int N = 100001;
vector<int> g[N];
int vis[N];
vector<int> path;
bool ok = false;

int dfs(int node, int parent) {
    vis[node] = 1;

    for (int child : g[node]) {
        if (vis[child] == 0) {
            int temp = dfs(child, node);
            if (temp) {
                if (ok) path.pb(child);
                if (temp == child) {
                    ok = false;
                }
                return temp;
            }
        } else {
            if (child != parent) {
                path.pb(child);
                ok = true;
                return child;
            }
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin>>t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        while (m--) {
            int x, y;
            cin >> x >> y;
            g[x].pb(y);
            g[y].pb(x);
        }

        rep(i, 1, n + 1) {
            if (vis[i] == 0) {
                int te = dfs(i, 0);
                if (te) {
                    if (path[0] != path[path.size() - 1]) path.pb(path[0]);
                    cout << path.size() << endl;
                    rep(i, 0, path.size()) { cout << path[i] << " "; }
                    break;
                }
                path.clear();
            }

            if (i == n) {
                cout << "IMPOSSIBLE" << endl;
            }
        }
    }
}