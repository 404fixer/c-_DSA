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
vi g[N], tg[N], order, scc;
int vis[N];

void dfs(int n) {
    vis[n] = 1;

    for (int c : g[n]) {
        if (!vis[c]) dfs(c);
    }

    order.pb(n);
}

void dfs2(int n) {
    vis[n] = 1;
    for (int c : tg[n]) {
        if (!vis[c]) dfs2(c);
    }

    scc.pb(n);
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
            int a, b;
            cin >> a >> b;
            g[a].pb(b);
            tg[b].pb(a);
        }

        rep(i, 1, n + 1) {
            if (!vis[i]) dfs(i);
        }

        rep(i, 1, n + 1) vis[i] = 0;

        reverse(all(order));
        vi ans(n + 1, 0);
        for (int x : order) {
            if (!vis[x]) {
                scc.clear();
                dfs2(x);

                if (scc.size() > 1) {
                    for (int y : scc) {
                        ans[y] = 1;
                    }
                }
            }
        }

        rep(i, 1, n + 1) { cout << ans[i] << " "; }
        cout << endl;
    }
}