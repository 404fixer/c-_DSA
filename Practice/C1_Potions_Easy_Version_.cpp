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
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] >= 0) ans++;
    }

    ll health = 0;
    multiset<ll> negs;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0)
            health += arr[i];
        else {
            health += arr[i];
            if (health < 0) {
                if (!negs.empty()) {
                    auto itr = --negs.end();
                    // debug(*itr);
                    if (*itr < abs(arr[i])) {
                        health -= arr[i];
                    } else {
                        negs.insert(-1 * arr[i]);
                        health += *itr;
                        negs.erase(itr);
                    }
                } else {
                    health -= arr[i];
                }
            } else {
                negs.insert(-1 * arr[i]);
            }
        }
        // debug(health);
    }

    ans += negs.size();
    cout << ans << endl;
}