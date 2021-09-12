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
#define pyn(flag) cout << (flag ? "YES" : "NO") << endl;

const int N = 1e5 + 1;
vi g[N], tg[N], vis(N), order, scc, value(N);

void dfs(int node) {
    vis[node] = 1;

    for (int child : g[node]) {
        if (!vis[child]) dfs(child);
    }

    order.pb(node);
}

void dfs2(int node) {
    vis[node] = 1;

    for (int child : tg[node]) {
        if (!vis[child]) dfs2(child);
    }

    scc.pb(node);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        order.clear();
        scc.clear();
        rep(i, 0, n) {
            g[i].clear();
            tg[i].clear();
            vis[i] = 0;
            value[i] = 0;
            cin >> value[i];
        }

        rep(i, 0, n) {
            int a = i;
            int b = (a + value[i] + 1) % n;

            g[a].pb(b);
            tg[b].pb(a);
        }

        rep(i, 0, n) {
            if (!vis[i]) dfs(i);
        }

        rep(i, 0, n + 1) { vis[i] = 0; }

        int ans = 0;
        reverse(order.begin(), order.end());
        for (int i : order) {
            if (!vis[i]) {
                scc.clear();
                dfs2(i);

                if (scc.size() == 1 && (scc[0] != g[scc[0]][0])) continue;
                ans += scc.size();
            }
        }

        cout << ans << endl;
    }
}