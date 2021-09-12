#include <bits/stdc++.h>
using namespace std;
#define ll int long long

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define endl "\n"
#define cy cout << "YES" << endl;
#define cn cout << "NO" << endl;

int main() {
    fast;
    ll test, n, i, j, k, a, b;
    cin >> test;
    while (test--) {
        cin >> a >> b >> n;
        ll arr1[n], arr2[n];
        ll maxi = 0;
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
            maxi = max(maxi, arr1[i]);
        }

        for (i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        for (i = 0; i < n; i++) {
            ll val = ceil(arr2[i] / (double)a);
            val *= arr1[i];
            b -= val;
        }
        if (b + maxi > 0) {
            cy;
        } else {
            cn;
        }
    }
    return 0;
}