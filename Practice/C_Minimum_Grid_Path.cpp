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
        ll c[n];
        ll min_h = LLONG_MAX;
        ll min_v = LLONG_MAX;
        for (int i = 0; i < n; i++) cin >> c[i];

        // ll min_ch = LLONG_MAX;
        // ll min_cv = LLONG_MAX;
        ll sum_h = (ll)0;
        ll sum_v = (ll)0;
        ll ans = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (c[i] < min_h) {
                    // min_ch = min(min_ch, sum_h + (c[i] * (n - (i / (ll)2))));
                    ll temp1, temp2;
                    if (i == 0) {
                        sum_h += c[i];
                        min_h = c[i];
                        continue;
                    } else {
                        temp1 = sum_h + (c[i] * (n - (i / (ll)2)));
                        temp2 =
                            (sum_v - min_v) + (min_v * (n - ((i - 1) / (ll)2)));
                    }

                    ans = min(ans, temp1 + temp2);
                    min_h = c[i];
                }
                sum_h += c[i];
            } else {
                if (c[i] < min_v) {
                    // min_cv = min(min_cv, sum_v + (c[i] * (n - (i / (ll)2))));
                    ll temp1 = sum_v + (c[i] * (n - (i / (ll)2)));
                    ll temp2 =
                        (sum_h - min_h) + (min_h * (n - ((i - 1) / (ll)2)));

                    ans = min(ans, temp1 + temp2);
                    min_v = c[i];
                }
                sum_v += c[i];
            }
        }

        cout << ans << endl;
    }
}