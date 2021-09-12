#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define mod 1000000007
#define debug(x) cout << #x << " " << x << endl;
using namespace std;

ll n;

bool possible(ll k) {
    ll start = 1;
    ll end = 1e5;
    debug(k);
    // debug(n);
    // if (k * (k + 1) / 2 > n) return false;
    ll temp_n = n - (k * (k + 1) / 2);
    while (start < end) {
        ll mid = (start + end) / 2;
        ll dup_n = (mid * (mid + 1) / 2);
        // if (k == 2) {
        //     debug(start);
        //     debug(end);
        //     debug(dup_n);
        // }
        if (dup_n == temp_n) {
            cout << "HERE" << endl;
            return true;
        } else if (dup_n > temp_n) {
            end = mid - 1;
        } else if (dup_n < temp_n) {
            start = mid + 1;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    ll start = 1, end = 1e5;
    bool ans = true;
    for (start = 1; start <= end; start++) {
        // ll mid = (start + end) / 2;
        // ll temp_f = mid * (mid + 1) / 2;
        if (start * (start + 1) / 2 > n) {
            break;
        }
        debug(start);
        if (possible(start)) {
            debug(start);
            cout << "YES" << endl;
            ans = false;
            break;
        }
    }
    if (ans) cout << "NO" << endl;
}