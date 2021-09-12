#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define mod 1000000007
#define debug(x) cout << #x << " " << x << endl;
using namespace std;

ll x, y, a, b;

bool possible(ll n) {
    ll start = 0;
    ll end = n;
    if (n > (x + y)) return false;

    while (start <= end) {
        ll mid = (end + start) / 2;
        ll reds = (n * b) + ((a - b) * mid);
        ll blues = (n * a) + ((b - a) * mid);

        if (reds <= x && blues <= y) return true;
        if (reds > x && blues > y) return false;

        if (reds > x) {
            if (a > b) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } else {
            if (b > a)
                end = mid - 1;
            else
                start = mid + 1;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> x >> y >> a >> b;

        ll start = 0;
        ll end = 1e9;
        ll ans = 0;
        while (start <= end) {
            ll mid = (end + start) / 2;
            if (possible(mid)) {
                start = mid + 1;
                ans = max(mid, ans);
            } else {
                end = mid - 1;
            }
        }

        cout << ans << endl;
    }
}