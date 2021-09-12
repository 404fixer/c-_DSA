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
        ll n, x, ti;
        cin >> n >> x >> ti;

        ll ans = (ll)0;
        if (x > ti) {
            ans = (ll)0;
        } else if (x == ti)
            ans = n - 1;
        else {
            // n-2 *
            ll temp = ti / x;
            if (temp > n) {
                temp = n - 1;
                ans += (temp * (temp + 1)) / 2;
                goto here;
            }
            // debug(temp);
            ans = temp * (n - temp);
            // debug(ans);
            ans += (temp * (temp + 1)) / 2;
            // debug(ans);
            ans -= temp;
            // debug(ans);
        }

        if (ans < 0) ans = (ll)0;

    here:
        cout << ans << endl;
    }
}