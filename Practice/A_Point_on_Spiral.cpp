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

    int x, y;
    cin >> x >> y;
    int ans = 0;
    int d = max(abs(x), abs(y));
    if (d == 0) {
        cout << 0 << endl;
        return 0;
    } else
        ans = (d - 1) * 4;
    // debug(ans);
    if (x == d && y != -1 * (d - 1) && y != -1 * (d)) ans++;
    if (y == d && x != d) ans += 2;
    if (x == -1 * d && y != d) ans += 3;
    if (y == -1 * d && x != -1 * d) ans += 4;

    cout << ans << endl;
}