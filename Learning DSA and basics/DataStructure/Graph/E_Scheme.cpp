/* Program By govindtomariiit */

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define ld long double
#define int ll
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
vi g[N], tg[N], vis(N), order, scc;
// which node belongs to which scc (representing through root node)
vi roots(N, 0);
vector<int> root_nodes;
// adj list of condensation graph
vi cg[N];
// in and out degree
vi in(N, 0), out(N, 0);

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

void dfs3(int n) {
    vis[n] = 1;

    for (int c : cg[n]) {
        if (!vis[c]) {
            dfs3(c);
        }
        in[c]++;
        out[n]++;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin>>t;
    while (t--) {
        int n;
        cin >> n;
        int a[n + 1];
        rep(i, 1, n + 1) {
            cin >> a[i];
            g[i].pb(a[i]);
            tg[a[i]].pb(i);
        }

        rep(i, 1, n + 1) {
            if (!vis[i]) dfs(i);
        }

        rep(i, 1, n + 1) vis[i] = 0;

        // traversing through transposed graph and looking for SCCs
        reverse(all(order));
        for (int x : order) {
            if (!vis[x]) {
                scc.clear();
                dfs2(x);

                // root of this SCC
                int root = scc.back();
                // assigning all nodes root node according to SCC
                for (int y : scc) {
                    // debugg(y, root);
                    roots[y] = root;
                }
                root_nodes.push_back(root);
            }
        }

        // traversing the original graph and forming condensation graph
        rep(i, 1, n + 1) {
            for (int x : g[i]) {
                // edge from parent to child, directed graph
                int root_p = roots[i];
                int root_c = roots[x];

                if (root_p != root_c) {
                    // it means they belong to two different SCC
                    // Now, we have to connect these two SCCs
                    cg[root_p].pb(root_c);
                }
            }
        }

        // Now, we've condensation graph
        // Obviously, this graph is acyclic.
        // Now, we've to find minimum number of edges to make it cyclic, that'll
        // be our answer

        rep(i, 1, n + 1) vis[i] = 0;

        // use the concept of in degree and out degree
        for (int i : root_nodes) {
            if (!vis[i]) {
                dfs3(i);
            }
        }

        int ans = 0;
        vi vin, vout, sep;
        for (int i : root_nodes) {
            if (in[i] == 0 && out[i] == 0)
                sep.pb(i);
            else if (in[i] == 0) {
                vin.pb(i);
            } else if (out[i] == 0) {
                vout.pb(i);
            }
        }

        vector<pii> res;

        bool in_temp = false, out_temp = false;
        if (!sep.empty()) {
            if (sep.size() > 1) {
                rep(i, 0, sep.size() - 1) {
                    // if (i == sep.size() - 1) {
                    //     res.pb({sep[i], sep[0]});
                    // } else {
                    res.pb({sep[i], sep[i + 1]});
                    // }
                }
            }
        } else {
            in_temp = true;
            out_temp = true;
        }

        // ans = max(root_nodes.size() - in_te, root_nodes.size() - out_te);
        // cout << ans << endl;
        auto itr = vout.begin();
        auto itr2 = vin.begin();

        while (itr != vout.end() && itr2 != vin.end()) {
            res.pb({*itr, *itr2});
            itr++;
            itr2++;

            if (itr == vout.end() && itr2 != vin.end()) {
                if (!out_temp) {
                    res.pb({sep[sep.size() - 1], *itr2});
                    out_temp = true;
                    itr2++;
                    if (itr2 == vin.end()) break;
                }
                itr--;
            } else if (itr != vout.end() && itr2 == vin.end()) {
                if (!in_temp) {
                    res.pb({*itr, sep[0]});
                    in_temp = true;
                    itr++;
                    if (itr == vout.end()) break;
                }
                itr2--;
            }
        }

        if (!in_temp) {
            if (!vin.empty()) {
                // res.pb({sep[sep.size() - 1], *vin.begin()});
                res.pb({*vin.begin(), sep[0]});
            } else if (!vout.empty()) {
                // res.pb({sep[sep.size() - 1], *vout.begin()});
                res.pb({*vout.begin(), sep[0]});
            } else {
                if (sep.size() > 1) {
                    res.pb({sep[sep.size() - 1], sep[0]});
                    out_temp = true;
                }
            }
        }
        if (!out_temp) {
            if (!vin.empty()) {
                res.pb({sep[sep.size() - 1], *vin.begin()});
                // res.pb({*vin.begin(), sep[0]});
            } else if (!vout.empty()) {
                res.pb({sep[sep.size() - 1], *vout.begin()});
                // res.pb({*vout.begin(), sep[0]});
            } else {
                if (sep.size() > 1) res.pb({sep[sep.size() - 1], sep[0]});
            }
        }

        cout << res.size() << endl;
        for (auto te : res) {
            cout << te.first << " " << te.sc << endl;
        }
    }
}