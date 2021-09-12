#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define mod 1000000007
#define debug(x) cout << #x << " " << x << endl;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> cnt(m, 0);
        for (int i = 0; i < n; i++) {
            ll temp;
            cin >> temp;
            cnt[(int)(temp % (ll)m)]++;
        }

        // for (int i = 0; i < m; i++) cout << cnt[i] << " ";
        // cout << endl;

        ll ans = 0;
        for (int i = 0; i <= (m / 2); i++) {
            if (i == 0) {
                if (cnt[i] != 0) ans++;
            } else if (m % 2 == 0 && i == (m / 2)) {
                if (cnt[i] != 0) ans++;
            } else {
                // add the remaining single ones
                if (cnt[i] != cnt[m - i])
                    ans += (ll)(max(cnt[i], cnt[m - i]) -
                                min(cnt[i], cnt[m - i]) - 1);

                // add 1 if any grouping is possible
                if (cnt[i] != 0 || cnt[m - i] != 0) ans++;
            }
        }

        cout << ans << endl;
    }
}