/* Program By govindtomariiit */

#include <bits/stdc++.h>
#define endl "\n"
#define int long long
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

int fact(int n);

int nCr(int n, int r) {
    return (fact(n) / ((fact(r) * fact(n - r)) % mod)) % mod;
}

// Returns factorial of n
int fact(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++) res = (res * i) % mod;
    return (res % mod);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        map<int, int> m;
        rep(i, 0, n) {
            cin >> arr[i];
            m[arr[i]]++;
        }
        sort(arr, arr + n);

        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (m[arr[i]] > k) {
                // cout << "here" << endl;
                debug(arr[i]);
                debug(m[arr[i]]);
                debug(k);
                ans = nCr(m[arr[i]], k);
                ans %= mod;
                debug(ans);
                break;
            }
            m[arr[i]]--;
            k--;
            if (k == 0) break;
        }

        if (ans == 0)
            cout << 1 << endl;
        else
            cout << ans << endl;
    }
}