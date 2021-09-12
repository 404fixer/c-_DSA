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
#define vi vector<int>
#define mii map<int, int>
#define mci map<char, int>
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

const int N = 1e5 + 1;
vi g[N];
int vis[N], in[N], low[N], timer;
bool hasBridge;
vector<pii> edges;

void dfs(int node, int par) {
    vis[node] = 1;
    in[node] = low[node] = timer++;

    for (int child : g[node]) {
        if (child == par) continue;

        if (vis[child] == 1) {
            low[node] = min(low[node], in[child]);

            if (in[node] > in[child]) {
                edges.pb({node, child});
            }
        } else {
            dfs(child, node);

            if (low[child] > in[node]) {
                hasBridge = true;
                return;
            }

            edges.pb({node, child});
            low[node] = min(low[child], low[node]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        rep(i, 0, m) {
            int x, y;
            cin >> x >> y;
            g[x].pb(y), g[y].pb(x);
        }

        dfs(1, -1);

        if (hasBridge) {
            cout << 0 << endl;
        } else {
            rep(i, 0, edges.size()) {
                cout << edges[i].fr << " " << edges[i].sc << endl;
            }
        }
    }
}