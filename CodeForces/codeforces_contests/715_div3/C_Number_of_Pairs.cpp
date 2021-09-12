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
        ll l, r;
        cin >> l >> r;
        vector<ll> v;
        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            v.push_back(x);
        }

        sort(v.begin(), v.end());
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ll op1 = lower_bound(v.begin(), v.end(), l - v[i]) - v.begin();
            ll op2 = upper_bound(v.begin(), v.end(), r - v[i]) - v.begin();
            // debug(op1);
            // debug(op2);
            if (l - v[i] <= v[i] && r - v[i] >= v[i]) {
                ans += (op2 - op1 - 1);
                continue;
            }
            ans += (op2 - op1);
            // debug(ans);
        }

        cout << ans / 2 << endl;
    }
}