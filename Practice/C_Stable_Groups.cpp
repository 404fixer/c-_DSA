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

    ll n, k, x;
    cin >> n >> k >> x;
    ll arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);
    map<ll, ll> m;
    ll gps = 0;
    for (int i = 1; i < n; i++) {
        if ((arr[i] - arr[i - 1]) > x) {
            if ((arr[i] - arr[i - 1]) % x == 0) {
                m[((arr[i] - arr[i - 1]) / x) - 1]++;
            } else
                m[(arr[i] - arr[i - 1]) / x]++;
            gps++;
        }
    }
    // debug(gps);

    if (gps > 0 && k > 0) {
        for (auto &itr : m) {
            // debug(itr.first);
            // debug(itr.second);
            // debug(k);
            // debug(gps);
            if (k >= (itr.first * itr.second)) {
                k -= (itr.first * itr.second);
                gps -= itr.second;
            } else {
                while (k >= itr.first) {
                    gps--;
                    k -= itr.first;
                }
                break;
            }
            // debug(gps);
            if (k == 0) break;
        }
    }

    cout << gps + 1 << endl;
}