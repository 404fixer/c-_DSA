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
multiset<int> g[N];
vi tg[N], vis(N);

void dfs(int node) {
    vis[node] = 1;

    for (int child : g[node]) {
        if (!vis[child]) dfs(child);
    }
}

void dfs2(int node) {
    vis[node] = 1;
    for (int child : tg[node]) {
        if (!vis[child]) dfs2(child);
    }
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

        rep(i, 0, m) {
            int x, y;
            cin >> x >> y;

            g[x].insert(y);
            tg[y].pb(x);
        }

        int cnt = 0, p, q;
        rep(i, 1, n + 1) {
            if (!vis[i]) {
                dfs(i);
                cnt++;
                if (cnt == 2) {
                    p = i - 1;
                    q = i;
                    break;
                }
            }
        }

        if (cnt == 2) {
            cout << "NO" << endl;
            // debugg(p, q);

            // if (g[q].find(p) != g[q].end()) {
            //     swap(p, q);
            // }
            cout << p << " " << q << endl;
        } else {
            rep(i, 1, n + 1) vis[i] = 0;
            cnt = 0;
            rep(i, 1, n + 1) {
                if (!vis[i]) {
                    dfs2(i);
                    cnt++;

                    if (cnt == 2) {
                        p = i - 1;
                        q = i;
                        break;
                    }
                }
            }

            if (cnt == 2) {
                cout << "NO\n";
                // if (g[p].find(q) == g[p].end()) swap(p, q);
                cout << q << " " << p << endl;
            } else {
                cout << "YES\n";
            }
        }
    }
}