#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nline endl
ll ans(ll a) {
    ll count1 = 0;
    for (ll i = 1; i <= a; i *= 10LL) {
        count1 += a / i;
    }
    return count1;
}
void solve() {
    int t;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        cout << ans(r) - ans(l) << nline;
    }
}

int main() { solve(); }