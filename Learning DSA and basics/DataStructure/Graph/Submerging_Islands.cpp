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
set<int> ap;

void dfs(int node, int par) {
    vis[node] = 1;
    in[node] = low[node] = timer++;

    int children = 0;
    for (int child : g[node]) {
        if (child == par) continue;

        if (vis[child]) {
            low[node] = min(low[node], in[child]);
        } else {
            dfs(child, node);

            if (low[child] >= in[node] && par != -1) ap.insert(node);
            low[node] = min(low[node], low[child]);

            children++;
        }
    }

    if (par == -1 && children > 1) {
        ap.insert(node);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin>>t;
    while (true) {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0) break;

        rep(i, 0, n + 1) {
            g[i].clear();
            vis[i] = 0;
            in[i] = 0, low[i] = 0;
        }
        ap.clear();
        timer = 1;

        rep(i, 0, m) {
            int x, y;
            cin >> x >> y;
            g[x].pb(y), g[y].pb(x);
        }

        rep(i, 1, n + 1) {
            if (!vis[i]) dfs(i, -1);
        }

        cout << ap.size() << endl;
    }
}