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
#define printyes cout << "YES" << endl;
#define printno cout << "NO" << endl;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin>>t;
    while (t--) {
        int n;
        cin >> n;
        int arr[2][n - 1];
        rep(i, 0, 2) rep(j, 0, n - 1) cin >> arr[i][j];
        int b[n];
        rep(i, 0, n) cin >> b[i];

        int ans = INT_MAX;
        rep(i, 0, n) {
            int go = 0;
            rep(j, 0, i) go += arr[0][j];
            go += b[i];
            rep(j, i, n - 1) go += arr[1][j];

            int comeback = INT_MAX;
            for (int j = n - 1; j >= 0; j--) {
                if (j == i) continue;

                int cb = 0;
                for (int k = n - 2; k >= j; k--) {
                    cb += arr[1][k];
                }
                cb += b[j];
                for (int k = j - 1; k >= 0; k--) {
                    cb += arr[0][k];
                }

                comeback = min(comeback, cb);
            }

            ans = min(ans, go + comeback);
            // debug(ans);
        }

        cout << ans << endl;
    }
}