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

    int n;
    cin >> n;
    ll arr[n];
    multiset<ll> neg;
    int ans = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] < 0)
            neg.insert(-1 * arr[i]);
        else {
            sum += arr[i];
            ans++;
        }
    }

    // -1
    // debug(ans);
    if (!neg.empty()) {
        for (auto &itr : neg) {
            // debug(ans);
            // debug(itr);
            sum -= itr;
            if (sum < 0) {
                // debug(ans);
                break;
            } else {
                ans++;
            }
        }
    }

    cout << ans << endl;
}