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
        int n, m;
        cin >> n >> m;
        string str[n];
        rep(i, 0, n) cin >> str[i];

        vector<int> v;
        rep(i, 0, n) {
            rep(j, 0, m) {
                if (str[i][j] == '*') {
                    v.pb(i);
                    v.pb(j);
                }
            }
        }

        int dp[n][m];
        mem1(dp);

        int ans = 0;

        for (int i = 0; i < v.size(); i += 2) {
            int l = v[i + 1], r = v[i + 1];
            int y = v[i];
            // debug(l);
            // debug(r);
            // debug(y);
            bool okay = true;
            while (okay) {
                if (l < 0 || r > m - 1 || y > n - 1) {
                    break;
                }

                if (dp[l][r] == 0)
                    break;
                else if (dp[l][r] == 1)
                    ans++;
                else {
                    int temp_l = l;

                    while (temp_l <= r) {
                        if (str[y][temp_l] == '*') {
                            if (temp_l == r) {
                                ans++;
                                dp[l][r] = 1;
                            }
                        } else {
                            okay = false;
                            break;
                        }

                        temp_l++;
                    }
                }

                l--;
                r++;
                y++;
            }
        }

        cout << ans << endl;
    }
}