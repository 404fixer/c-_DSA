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
        int n;
        cin >> n;
        ll u, v;
        cin >> u >> v;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];

        ll ans = LLONG_MAX;
        for (int i = 1; i < n; i++) {
            if (abs(arr[i] - arr[i - 1]) >= 2) ans = (ll)0;
            if (abs(arr[i] - arr[i - 1]) == 1) ans = min(ans, min(u, v));
            if (arr[i] == arr[i - 1]) ans = min(ans, v + min(u, v));
        }

        cout << ans << endl;
    }
}