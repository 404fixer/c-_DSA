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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s[n];
        rep(i, 0, n) { cin >> s[i]; }

        int a = s[0][1], b = s[1][0];
        int c = s[n - 1][n - 2], d = s[n - 2][n - 1];

        vector<pii> pr;

        if (a == b) {
            // c = d = !a
            if (c == a) pr.pb({n, n - 1});
            if (d == a) pr.pb({n - 1, n});
        } else if (c == d) {
            // a = b = !c
            if (a == c) pr.pb({1, 2});
            if (b == c) pr.pb({2, 1});
        } else {
            // a = b and c = d and c != a
            pr.pb({2, 1});
            if (c == a) pr.pb({n, n - 1});
            if (d == a) pr.pb({n - 1, n});
        }

        cout << pr.size() << "\n";
        for (auto x : pr) {
            cout << x.fr << " " << x.sc << "\n";
        }
    }
}