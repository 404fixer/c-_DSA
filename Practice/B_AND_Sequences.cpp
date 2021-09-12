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
        int n;
        cin >> n;

        ll arr[n];
        ll temp = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (i == 0)
                temp = arr[i];
            else
                temp = temp & arr[i];
        }

        ll cnt = 0;
        int j = 0, k = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == temp) {
                cnt++;
                if (cnt == 1) {
                    j = i;
                    swap(arr[0], arr[i]);
                }
                if (cnt == 2) {
                    k = i;
                }
            }
        }
        if (n >= 2) swap(arr[n - 1], arr[k]);

        // debug(temp);
        // debug(cnt);

        if (cnt < 2)
            cout << 0 << endl;
        else {
            ll prefix_and = arr[0];
            ll sufix_and = arr[n - 1];
            bool isOkay = true;
            for (int i = 1; i < n - 2; i++) {
                prefix_and = prefix_and & arr[i];
                if (prefix_and != temp) {
                    isOkay = false;
                    break;
                }
            }
            for (int i = n - 2; i >= 0; i--) {
                sufix_and = sufix_and & arr[i];
                if (sufix_and != temp) {
                    isOkay = false;
                    break;
                }
            }

            if (isOkay) {
                ll ans = (ll)1;
                // debug(temp);
                // debug(cnt);
                ans = (cnt * (cnt - (ll)1)) % mod;
                // ans %= mod;
                // debug(ans);

                n = n - 2;
                while (n != 0) {
                    ans = (ans * (ll)n) % mod;
                    n--;
                }
                // debug(ans);

                cout << ans << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
}