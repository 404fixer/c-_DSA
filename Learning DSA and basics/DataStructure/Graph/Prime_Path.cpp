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
vector<int> g[N];
vector<int> primes;
int dist[N], vis[N];

bool isPrime(int x) {
    for (int i = 2; (i * i) <= x; i++) {
        if (x % i == 0) return false;
    }

    return true;
}

bool valid(int a, int b) {
    int cnt = 0;

    while (a > 0) {
        if ((a % 10) != (b % 10)) cnt++;

        a = a / 10;
        b = b / 10;
    }

    if (cnt == 1) return true;
    return false;
}

void buildGraph() {
    rep(i, 1000, 10000) {
        if (isPrime(i)) primes.pb(i);
    }

    rep(i, 0, primes.size()) {
        rep(k, i + 1, primes.size()) {
            int a = primes[i];
            int b = primes[k];
            if (valid(a, b)) {
                g[a].pb(b), g[b].pb(a);
            }
        }
    }
}

void bfs(int n) {
    queue<int> q;
    q.push(n);

    dist[n] = 0;
    vis[n] = 1;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int x : g[curr]) {
            if (vis[x] == 0) {
                vis[x] = 1;
                dist[x] = dist[curr] + 1;
                q.push(x);
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    buildGraph();
    while (t--) {
        int a, b;
        cin >> a >> b;

        rep(i, 1000, 10000) { dist[i] = -1, vis[i] = 0; }

        bfs(a);

        if (dist[b] == -1)
            cout << "Impossible" << endl;
        else
            cout << dist[b] << endl;
    }
}