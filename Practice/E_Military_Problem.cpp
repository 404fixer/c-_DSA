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

#define N 200000
vector<ll> a[N + 1];
ll child[N + 1] = {0};
ll vis[N + 1] = {0};
vector<ll> s;

void dfs(ll u) {
    vis[u] = 1;
    s.pb(u);

    for (int i = 0; i < a[u].size(); i++) {
        ll v = a[u][i];
        if (vis[v] == 0) {
            dfs(v);
            child[u] += child[v];
        }
    }
    child[u]++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin>>t;
    while (t--) {
        ll n;
        ll q;
        cin >> n >> q;

        for (int i = 2; i <= n; i++) {
            ll t;
            cin >> t;
            a[t].pb(i);
            a[i].pb(t);
        }

        dfs(1);
        vector<ll> idx(n + 1, 0);
        for (int i = 0; i < n; i++) idx[s[i]] = i;

        while (q--) {
            ll a, b;
            cin >> a >> b;
            if (b > child[a])
                cout << -1 << endl;
            else
                cout << s[idx[a] + b - 1] << endl;
        }
    }
}