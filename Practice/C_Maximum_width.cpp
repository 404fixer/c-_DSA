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
    // cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s, t;
        cin >> s >> t;

        int l[m], r[m];
        int j = 0;
        rep(i, 0, m) {
            while (j < n) {
                if (s[j] == t[i]) {
                    l[i] = j;
                    j++;
                    break;
                }
                j++;
            }
        }

        int k = n - 1;
        for (int i = m - 1; i >= 0; i--) {
            while (k < n) {
                if (s[k] == t[i]) {
                    r[i] = k;
                    k--;
                    break;
                }
                k--;
            }
        }

        // check for max
        int ans = INT_MIN;
        rep(i, 1, m) { ans = max(ans, r[i] - l[i - 1]); }
        cout << ans << endl;
    }
}