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

const int N = 1e3 + 1;

int parent[N], sz1[N];
int par[N], sz2[N];

void make_pair(int v) {
    parent[v] = v;
    sz1[v] = 1;
}

int find_set(int v) {
    if (v == parent[v]) return v;

    return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b) {
    a = find_set(a), b = find_set(b);

    if (a != b) {
        if (sz1[a] < sz1[b]) swap(a, b);

        parent[b] = a;
        sz1[a] += sz1[b];
    }
}

void mp(int v) {
    par[v] = v;
    sz2[v] = 1;
}

int fis(int v) {
    if (v == par[v]) return v;

    return par[v] = fis(par[v]);
}

void us(int a, int b) {
    a = fis(a), b = fis(b);

    if (a != b) {
        if (sz2[a] < sz2[b]) swap(a, b);

        par[b] = a;
        sz2[a] += sz2[b];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        int n, m, q;
        cin>>n>>m>>q;

        rep(i, 1, n+1) {
            make_pair(i);
            mp(i);
        }

        rep(i, 0, m) {
            int x, y;
            cin>>x>>y;
            union_set(x, y);
        }

        rep(i, 0, q) {
            int x, y;
            cin>>x>>y;
            us(x, y);
        }

        vector<pii> ans;
        rep(i, 1, n+1) {
            rep(j, 1, n+1) {
                if((find_set(i) != find_set(j)) && (fis(i) != fis(j))) {
                    ans.pb({i, j});
                    union_set(i, j);
                    us(i, j);
                }
            }
        }

        cout<<ans.size()<<endl;
        for(auto te: ans) cout<<te.fr<<" "<<te.sc<<endl;
    }
}