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
vi g[N];
stack<int> st;
bool vis[N], onStack[N];
int in[N], low[N], timer = 0, scc = 0;

void dfs(int node) {
    // Implementing Tarjan's Algorithm
    vis[node] = 1;
    onStack[node] = true;
    in[node] = low[node] = timer++;
    st.push(node);

    for (int child : g[node]) {
        if (vis[child]) {
            if (onStack[child]) low[node] = min(low[node], in[child]);
        } else {
            dfs(child);
            if (onStack[child]) low[node] = min(low[node], low[child]);
        }
    }
    if (in[node] == low[node]) {
        // we found a SCC
        scc++;
        cout << "SCC : " << scc << endl;
        while (st.top() != node) {
            cout << st.top() << " ";
            onStack[st.top()] = false;
            st.pop();
        }
        cout << st.top() << endl;
        onStack[st.top()] = false;
        st.pop();
    }
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
        }
        rep(i, 1, n + 1) vis[i] = false, onStack[i] = false;

        rep(i, 1, n + 1) {
            if (!vis[i]) dfs(i);
        }
    }
}