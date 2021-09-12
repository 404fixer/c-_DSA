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
    // cin>>t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        string s;
        cin >> s;
        // abc, acb, bac, bca, cab, cba,
        int pre[6][n + 1];
        vector<string> perm = {"abc", "acb", "bac", "bca", "cab", "cba"};
        vector<string> possible_strings(6, "");
        rep(i, 0, n) {
            rep(j, 0, 6) { possible_strings[j] += perm[j][i % 3]; }
        }

        rep(i, 0, n) {
            rep(j, 0, 6) {
                if (i == 0)
                    pre[j][i] = 0;
                else
                    pre[j][i] = pre[j][i - 1];
                if (s[i] != possible_strings[j][i]) pre[j][i]++;
            }
        }

        while (m--) {
            int x, y;
            cin >> x >> y;
            int ans = INT_MAX;
            rep(i, 0, 6) {
                // debugg(pre[i][y - 1], pre[i][x - 1]);
                if (x > 1)
                    ans = min(ans, pre[i][y - 1] - pre[i][x - 2]);
                else
                    ans = min(ans, pre[i][y - 1]);
            }

            cout << ans << endl;
        }
    }
}