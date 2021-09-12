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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        set<int> g[n + 1];
        vector<int> arr(n + 1, 0);

        int cnt = 0;
        rep(i, 0, m) {
            int x, y;
            cin >> x >> y;
            g[x].insert(y), g[y].insert(x);
            if (arr[min(x, y)] == 0) {
                arr[min(x, y)] = 1;
                cnt++;
            }
            // debug(cnt);
        }

        int q;
        cin >> q;
        while (q--) {
            int x;
            cin >> x;
            if (x == 3) {
                cout << n - cnt << endl;
            } else {
                int y, z;
                cin >> y >> z;

                if (x == 1) {
                    g[y].insert(z), g[z].insert(y);
                    if (arr[min(z, y)] == 0) {
                        arr[min(z, y)] = 1;
                        cnt++;
                    }
                } else {
                    g[y].erase(z);
                    g[z].erase(y);
                    if (g[min(y, z)].empty() ||
                        *(--g[min(y, z)].end()) < min(y, z)) {
                        cnt--;
                        arr[min(y, z)] = 0;
                    }
                }
            }
            // debug(cnt);
        }
    }
}