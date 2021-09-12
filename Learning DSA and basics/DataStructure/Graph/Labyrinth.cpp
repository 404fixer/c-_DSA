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

const int N = 1001;
int n, m;
string g[N];
int vis[N][N];
pii parent[N][N];
char how_it_came_here[N][N];
string ans;

int isValid(int i, int j) {
    if (i >= 0 && i < n && j < m && j >= 0 && g[i][j] == 'B') return 2;
    if (i >= 0 && i < n && j < m && j >= 0 && g[i][j] == '.') return 1;

    return 0;
}

bool bfs(int i, int j) {
    vis[i][j] = 1;
    queue<pii> q;
    q.push({i, j});

    while (!q.empty()) {
        i = q.front().first, j = q.front().sc;
        // debugg(i, j);
        if (isValid(i - 1, j) == 2) {
            ans.pb('U');
            int x = i, y = j;
            while (true) {
                if (g[x][y] == 'A') break;
                ans.pb(how_it_came_here[x][y]);
                int te = x;
                x = parent[x][y].fr;
                y = parent[te][y].sc;
            }
            return true;
        }

        if (isValid(i + 1, j) == 2) {
            ans.pb('D');
            int x = i, y = j;
            while (true) {
                // debugg(x, y);
                if (g[x][y] == 'A') break;

                ans.pb(how_it_came_here[x][y]);
                // debugg(x, y);
                // debugg(parent[x][y].fr, parent[x][y].sc);
                int te = x;
                x = parent[x][y].fr;
                y = parent[te][y].sc;
            }
            return true;
        }

        if (isValid(i, j - 1) == 2) {
            ans.pb('L');
            int x = i, y = j;
            while (true) {
                if (g[x][y] == 'A') break;

                ans.pb(how_it_came_here[x][y]);
                int te = x;
                x = parent[x][y].fr;
                y = parent[te][y].sc;
            }
            return true;
        }

        if (isValid(i, j + 1) == 2) {
            ans.pb('R');
            int x = i, y = j;
            while (true) {
                if (g[x][y] == 'A') break;

                ans.pb(how_it_came_here[x][y]);
                int te = x;
                x = parent[x][y].fr;
                y = parent[te][y].sc;
            }
            return true;
        }

        if (isValid(i - 1, j) == 1 && vis[i - 1][j] == 0) {
            // cout << 'a' << endl;
            how_it_came_here[i - 1][j] = 'U';
            parent[i - 1][j] = {i, j};
            q.push({i - 1, j});
            vis[i - 1][j] = 1;
        }
        if (isValid(i + 1, j) == 1 && vis[i + 1][j] == 0) {
            // cout << 'b' << endl;
            how_it_came_here[i + 1][j] = 'D';
            parent[i + 1][j] = {i, j};
            // debugg(i + 1, j);
            // debugg(parent[i + 1][j].fr, parent[i + 1][j].sc);
            q.push({i + 1, j});
            vis[i + 1][j] = 1;
        }
        if (isValid(i, j - 1) == 1 && vis[i][j - 1] == 0) {
            // cout << 'c' << endl;

            how_it_came_here[i][j - 1] = 'L';
            parent[i][j - 1] = {i, j};
            q.push({i, j - 1});
            vis[i][j - 1] = 1;
        }
        if (isValid(i, j + 1) == 1 && vis[i][j + 1] == 0) {
            // cout << 'd' << endl;

            how_it_came_here[i][j + 1] = 'R';
            parent[i][j + 1] = {i, j};
            q.push({i, j + 1});
            vis[i][j + 1] = 1;
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
        rep(i, 0, n) cin >> g[i];

        // doing bfs can help in finding shortest path
        // then, now how to backtrack
        bool ans_te, found = false;
        rep(i, 0, n) {
            rep(j, 0, m) {
                if (g[i][j] == 'A') {
                    found = true;
                    ans_te = bfs(i, j);
                    break;
                }
            }
            if (found) break;
        }

        if (ans_te) {
            py;
            cout << ans.size() << endl;
            reverse(all(ans));
            cout << ans << endl;
        } else
            pn;
    }
}