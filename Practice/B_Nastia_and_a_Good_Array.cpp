#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define mod 1000000007
#define debug(x) cout << #x << " " << x << endl;
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];

        bool ans = false;
        for (int i = 1; i < n; i++) {
            if (gcd(arr[i], arr[i - 1]) != (ll)1) {
                ans = true;
                break;
            }
        }

        if (ans) {
            ll pos = 0;
            ll val = LLONG_MAX;
            for (int i = 0; i < n; i++) {
                if (arr[i] < val) {
                    val = arr[i];
                    pos = i;
                }
            }
            cout << n - 1 << endl;
            for (int i = 0; i < n; i++) {
                if (i != pos)
                    cout << i + 1 << " " << pos + 1 << " "
                         << (val + abs(pos - (i))) << " " << val << endl;
            }
        } else {
            cout << 0 << endl;
        }
    }
}