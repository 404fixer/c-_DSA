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

    // int t;
    // cin >> t;
    // while (t--) {
    int n;
    cin >> n;
    set<ll> s;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        s.insert(x);
    }

    cout << (n - 1) / 2 << endl;
    ll ans[n];
    auto itr = s.begin();
    for (int i = 1; i < n; i += 2) {
        ans[i] = *itr;
        itr++;
    }
    for (int i = 0; i < n; i += 2) {
        ans[i] = *itr;
        itr++;
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
    // }

    // 1 4 2 5 3
}