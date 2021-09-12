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
        int n, q;
        cin >> n >> q;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        int brr[q][2];
        for (int j = 0; j < q; j++) {
            cin >> brr[j][0] >> brr[j][1];
        }

        // for (int j = 0; j < q; j++) {
        //     cout << brr[j][0] << brr[j][1] << endl;
        // }

        ll pre[n], suf[n];
        rep(i, 0, n) {
            if (i == 0)
                pre[0] = (ll)arr[i];
            else
                pre[i] = (ll)gcd(pre[i - 1], arr[i]) % mod;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1)
                suf[i] = (ll)arr[i];
            else
                suf[i] = (ll)gcd(suf[i + 1], arr[i]) % mod;
        }

        ll prev = 0;
        for (int i = 0; i < q; i++) {
            ll ans = 0;
            if (brr[i][0] == 1) {
                ans = (ll)gcd(brr[i][1] * arr[brr[i][0] - 1], suf[brr[i][0]]);
            } else if (brr[i][0] == n) {
                ans =
                    (ll)gcd(brr[i][1] * arr[brr[i][0] - 1], pre[brr[i][0] - 2]);
            } else {
                ans = (ll)gcd(brr[i][1] * arr[brr[i][0] - 1],
                              gcd(suf[brr[i][0]], pre[brr[i][0] - 2]));
            }
            // arr[brr[i][0] - 1] *= brr[i][1];
            // debug(i);
            if (i != 0) ans = gcd(prev, ans) % mod;
            prev = ans;

            cout << ans % mod << endl;
        }
    }
}