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
#define printyes cout << "YES" << endl
#define printno cout << "NO" << endl

vector<int> g[2001];
int vis[2001];
int co[2001];

bool dfs(int x, int clr) {
    vis[x] = 1;
    co[x] = clr;

    for (int child : g[x]) {
        if (vis[child] == 0) {
            if (!dfs(child, clr ^ 1)) return false;
        } else {
            if (co[child] == co[x]) return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    int cnt = 1;
    while (t--) {
        int n, m;
        cin >> n >> m;

        rep(i, 0, 2001) {
            g[i].clear();
            vis[i] = 0;
            co[i] = 0;
        }

        while (m--) {
            int a, b;
            cin >> a >> b;

            g[a].pb(b);
            g[b].pb(a);
        }

        bool ans = true;
        rep(i, 1, n + 1) if (vis[i] == 0) if (!dfs(i, 0)) {
            ans = false;
            break;
        }
        if (ans) {
            cout << "Scenario #" << cnt << ":" << endl;
            cout << "No suspicious bugs found!";
        } else {
            cout << "Scenario #" << cnt << ":" << endl;
            cout << "Suspicious bugs found!" << endl;
        }

        cnt++;
    }
}