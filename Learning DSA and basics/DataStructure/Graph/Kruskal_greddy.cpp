// Kruskal's Algorithm for finding minimum spanning tree.
// Greedy Based Approach

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

struct Edge {
    int u, v, w;
    bool operator<(Edge const& other) const { return (w < other.w); }
};

vector<Edge> edges;
vector<int> tree_id(N);
int cost = 0;
vector<Edge> result;

void findMSP(int n) {
    rep(i, 0, n + 1) tree_id[i] = i;

    sort(edges.begin(), edges.end());

    for (Edge e : edges) {
        if (tree_id[e.u] != tree_id[e.v]) {
            cost += e.w;
            result.pb(e);

            int old_id = tree_id[e.u], new_id = tree_id[e.v];
            rep(i, 1, n + 1) {
                if (tree_id[i] == old_id) {
                    tree_id[i] = new_id;
                }
            }
        }
    }
}

// bool cmp(int a, int b) {
//     if (a < b) return true;
//     return false;
// }

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
            int x, y, w;
            cin >> x >> y >> w;

            edges.pb({x, y, w});
        }

        findMSP(n);
        rep(i, 0, result.size()) {
            cout << result[i].u << " " << result[i].v << " " << result[i].w
                 << endl;
        }
        cout << cost << endl;
    }
}