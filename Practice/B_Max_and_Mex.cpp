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
        ll n, k;
        cin >> n >> k;
        set<ll> s;
        for (ll i = 0; i < n; i++) {
            ll x;
            cin >> x;
            s.insert(x);
        }

        ll big = *(--(s.end()));
        ll small = -1;
        ll temp = (ll)0;
        for (auto itr : s) {
            if (itr != temp) {
                small = temp;
                break;
            }
            temp++;
        }

        // debug(small);
        // debug(big);
        if (k == 0)
            cout << n << endl;
        else if (small == -1)
            cout << n + k << endl;
        else {
            if (s.find((ll)ceil(((double)small + (double)big) / 2)) !=
                s.end()) {
                cout << n << endl;
            } else {
                cout << n + 1 << endl;
            }
        }
    }
}