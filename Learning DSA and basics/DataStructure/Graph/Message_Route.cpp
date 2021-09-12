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

const int N = 100005;
int n, m;
vector<int> g[N];
int vis[N];
int parent[N];
vector<int> ans;

bool bfs(int node) {
    vis[node] = 1;
    queue<int> q;
    q.push(node);

    while (!q.empty()) {
        for (int x : g[q.front()]) {
            if (vis[x] == 0) {
                parent[x] = q.front();
                if (x == n) {
                    ans.pb(x);
                    while (x != 1) {
                        ans.pb(parent[x]);
                        x = parent[x];
                    }
                    return true;
                }
                q.push(x);
                vis[x] = 1;
            }
        }
        q.pop();
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin>>t;
    while (t--) {
        cin >> n >> m;

        rep(i, 0, m) {
            int a, b;
            cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
        }

        if (bfs(1)) {
            reverse(all(ans));
            cout << ans.size() << endl;
            for (int x : ans) {
                cout << x << " ";
            }
            cout << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
}