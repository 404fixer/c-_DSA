/* Program By govindtomariiit */

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define int long long
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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    int cnt = 1;
    while (t--) {
        int arr[3][3];
        rep(i, 0, 3) {
            rep(j, 0, 3) {
                if (i == 1 && j == 1) continue;
                cin >> arr[i][j];
            }
        }

        // rep(i, 0, 3) {
        //     rep(j, 0, 3) { cout << arr[i][j] << " "; }
        //     cout << endl;
        // }

        int ans = 0;
        if (arr[0][1] * 2 == arr[0][0] + arr[0][2]) ans++;
        if (arr[2][1] * 2 == arr[2][0] + arr[2][2]) ans++;
        if (arr[1][0] * 2 == arr[0][0] + arr[2][0]) ans++;
        if (arr[1][2] * 2 == arr[0][2] + arr[2][2]) ans++;

        // debug(ans);
        vector<int> v;
        if ((abs(arr[0][0]) % 2 == 0 && abs(arr[2][2]) % 2 == 0) ||
            (abs(arr[0][0]) % 2 == 1 && abs(arr[2][2]) % 2 == 1)) {
            // cout << "a" << endl;
            v.pb((arr[0][0] + arr[2][2]) / 2);
        }
        if ((abs(arr[0][2]) % 2 == 0 && abs(arr[2][0]) % 2 == 0) ||
            (abs(arr[0][2]) % 2 == 1 && abs(arr[2][0]) % 2 == 1)) {
            // cout << "b" << endl;

            v.pb((arr[0][2] + arr[2][0]) / 2);
        }
        if ((abs(arr[1][0]) % 2 == 0 && abs(arr[1][2]) % 2 == 0) ||
            (abs(arr[1][0]) % 2 == 1 && abs(arr[1][2]) % 2 == 1)) {
            // cout << "c" << endl;

            v.pb((arr[1][0] + arr[1][2]) / 2);
        }
        if ((abs(arr[0][1]) % 2 == 0 && abs(arr[2][1]) % 2 == 0) ||
            (abs(arr[0][1]) % 2 == 1 && abs(arr[2][1]) % 2 == 1)) {
            // cout << "d" << endl;
            v.pb((arr[0][1] + arr[2][1]) / 2);
        }

        sort(all(v));
        map<int, int> m;
        for (int i = 0; i < v.size(); i++) {
            m[v[i]]++;
        }

        int temp = INT_MIN;
        for (auto &itr : m) {
            temp = max(temp, itr.second);
        }
        if (!m.empty()) ans += temp;

        cout << "Case #" << cnt << ": " << ans << endl;
        cnt++;
    }
}