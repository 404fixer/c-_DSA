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
int n, m;
vector<int> g[N];
int vis[N], dist[N];

void bfs(int n) {
    vis[n] = 1;
    queue<int> q;
    q.push(n);
    dist[n] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int x : g[curr]) {
            if (vis[x] == 0) {
                q.push(x);
                dist[x] = dist[curr] + 1;
                vis[x] = 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        cin >> n >> m;

        rep(i, 0, n + 1) {
            g[i].clear();
            vis[i] = 0;
            dist[i] = 0;
        }

        rep(i, 0, m) {
            int x, y;
            cin >> x >> y;
            g[x].pb(y);
            g[y].pb(x);
        }

        bfs(1);
        cout << dist[n] << endl;
    }
}