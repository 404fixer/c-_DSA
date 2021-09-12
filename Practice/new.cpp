#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pp pair<int, int>
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define ll long long
#define M 1000000007
using namespace std;

int main() {
    fast int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];

        ll ans = 1e18;

        int nx, ny;
        nx = ny = n;
        ll tmpx, tmpy;
        tmpx = tmpy = 0;

        ll a, b;
        a = b = 1e18;
        for (int i = 0; i < A.size(); i++) {
            if (i % 2 == 0) {
                a = min(a, (ll)A[i]);
                tmpx += (ll)A[i];
                nx--;
            } else {
                b = min(b, (ll)A[i]);
                tmpy += (ll)A[i];
                ny--;
            }
            if (i == 0) continue;

            ans = min(ans, (ll)tmpx + tmpy + a * nx + b * ny);
        }
        cout << ans << "\n";
    }
    return 0;
}
