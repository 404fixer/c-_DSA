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
#define py cout << "YES" << endl
#define pn cout << "NO" << endl

const int N = 55;
string mat[N];
int vis[N][N];
int n, m;
int te[4] = {-1, 1};

bool isValid(int i, int j) {
    if (i >= 0 && i < n && j >= 0 && j < m && vis[i][j] == 0) return true;

    return false;
}

void dfs(int i, int j) {
    vis[i][j] = 1;

    if (isValid(i - 1, j) && mat[i - 1][j] == '#') {
        dfs(i - 1, j);
    }
    if (isValid(i + 1, j) && mat[i + 1][j] == '#') {
        dfs(i + 1, j);
    }
    if (isValid(i, j - 1) && mat[i][j - 1] == '#') {
        dfs(i, j - 1);
    }
    if (isValid(i, j + 1) && mat[i][j + 1] == '#') {
        dfs(i, j + 1);
    }
}

bool canOne() {
    rep(i, 0, n) {
        rep(j, 0, m) { vis[i][j] = 0; }
    }

    int cnt = 0;
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (mat[i][j] == '#' && vis[i][j] == 0) {
                dfs(i, j);
                cnt++;
            }

            if (cnt > 1) return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        cin >> n >> m;

        rep(i, 0, n) { cin >> mat[i]; }

        int cnt = 0;

        rep(i, 0, n) { rep(j, 0, m) if (mat[i][j] == '#') cnt++; }
        int ans = 1;
        if ((n == 1 || m == 1) && cnt > 2) {
            ans = 1;
            cout << ans << endl;
            break;
        }

        ans = 2;

        rep(i, 0, n) {
            rep(j, 0, m) {
                if (mat[i][j] == '#') {
                    mat[i][j] = '.';
                    if (canOne()) {
                        ans = 1;
                        break;
                    }
                    mat[i][j] = '#';
                }
            }
            if (ans == 1) break;
        }

        if (cnt < 3) ans = -1;

        cout << ans << endl;
    }
}