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

const int N = 1000001;
vector<int> g[N];
int vis[N], cc[N];

void bfs(int src, int cc_num) {
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    cc[src] = cc_num;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int x : g[curr]) {
            if (vis[x] == 0) {
                q.push(x);
                cc[x] = cc_num;
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
        int a, b;
        cin >> a >> b;

        rep(i, 0, a + 1) {
            vis[i] = 0, cc[i] = 0;
            g[i].clear();
        }

        vector<pii> vp;
        rep(i, 0, b) {
            int x, y;
            char c, d;
            cin >> x >> c;
            if (c == '=') {
                cin >> y;
                g[x].pb(y);
                g[y].pb(x);
            } else {
                cin >> d >> y;
                vp.pb({x, y});
            }
        }

        int cnt = 1;
        rep(i, 1, a + 1) {
            if (vis[i] == 0) {
                bfs(i, cnt);
                cnt++;
            }
        }

        bool ans = true;
        rep(i, 0, vp.size()) {
            if (cc[vp[i].fr] == cc[vp[i].sc]) {
                ans = false;
                break;
            }
        }

        if (ans)
            py;
        else
            pn;
    }
}