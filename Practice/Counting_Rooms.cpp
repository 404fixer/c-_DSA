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
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define debug(x) cout << #x << " " << x << endl;
#define mod 1000000007
const long long inf = 1e18;
using namespace std;

char arr[1001][1001];
bool vis[1001][1001];
int n, m;

bool isValid(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > m) return false;

    if (arr[x][y] == '#' || vis[x][y]) return false;

    return true;
}

void dfs(int x, int y) {
    vis[x][y] = true;

    if (isValid(x - 1, y)) dfs(x - 1, y);
    if (isValid(x + 1, y)) dfs(x + 1, y);
    if (isValid(x, y + 1)) dfs(x, y + 1);
    if (isValid(x, y - 1)) dfs(x, y - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        cin >> n >> m;

        rep(i, 1, n + 1) { rep(j, 1, m + 1) cin >> arr[i][j]; }

        rep(i, 0, n + 1) rep(j, 0, m + 1) vis[i][j] = false;

        int cnt = 0;
        rep(i, 1, n + 1) {
            rep(j, 1, m + 1) {
                if (!vis[i][j] && arr[i][j] == '.') {
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << endl;
    }
}