/* Program By govindtomariiit */

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
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
        int x, y;
        cin >> x >> y;
        string str;
        cin >> str;

        int u = 0, d = 0, r = 0, l = 0;
        rep(i, 0, str.length()) {
            if (str[i] == 'U')
                u++;
            else if (str[i] == 'D')
                d++;
            else if (str[i] == 'R')
                r++;
            else
                l++;
        }

        if (x > 0) {
            if (r < x) {
                cout << "NO" << endl;
                continue;
            }
        }
        if (y > 0) {
            if (u < y) {
                cout << "NO" << endl;
                continue;
            }
        }
        if (x < 0) {
            if (l < abs(x)) {
                cout << "NO" << endl;
                continue;
            }
        }
        if (y < 0) {
            if (d < abs(y)) {
                cout << "NO" << endl;
                continue;
            }
        }

        cout << "YES" << endl;
    }
}