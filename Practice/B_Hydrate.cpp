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

    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    if (d * c > b) {
        // debug(((d * c) - b));
        ll ans = ceil(((double)a / ((d * c) - b)));
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}