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

    ll n;
    cin >> n;

    bool ans = true;
    int cnt = 0;
    for (int i = 2; i < n; i++) {
        ans = true;
        for (int j = 1; j < n; j++) {
            if (j == (n - 1) && ans && (((ll)pow(i, j) - 1) % n == 0)) {
                cnt++;
                // debug(i);
                // debug(j);
                // debug(cnt);
            }
            if (j < n - 1 && ((ll)pow(i, j) - 1) % n == 0) {
                debug(i);
                debug(j);
                debug(cnt);
                ans = false;
                break;
            }
        }
    }

    cout << cnt << endl;
}