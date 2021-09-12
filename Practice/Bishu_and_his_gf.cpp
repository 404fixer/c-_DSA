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

vector<int> v[1001];
int vis[1001], dist[1001];

void dfs(int node, int d) {
    vis[node] = 1;
    dist[node] = d;

    for (int child : v[node]) {
        if (vis[child] == 0) dfs(child, dist[node] + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        int n, q, a, b;
        cin >> n;
        rep(i, 1, n) {
            cin >> a >> b;
            v[a].pb(b);
            v[b].pb(a);
        }

        dfs(1, 0);

        int ans = -1, te = INT_MAX;
        cin >> q;
        while (q--) {
            int g;
            cin >> g;
            if (dist[g] < te) {
                ans = g;
                te = dist[g];
            } else if (dist[g] == te) {
                ans = min(ans, g);
            }
        }

        cout << ans << endl;
    }
}