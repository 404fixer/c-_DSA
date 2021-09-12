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
        int n, k;
        cin >> n >> k;
        ll p[n];
        for (int i = 0; i < n; i++) cin >> p[i];

        ll sum = 0;
        ll ans = 0;
        double temp2 = (double)k / 100;
        for (int i = 0; i < n; i++) {
            if (i == 0)
                sum = p[i];
            else {
                ll temp = (ll)ceil((double)p[i] / temp2);
                if (sum < temp) {
                    ans += (temp - sum);
                    sum += (temp - sum);
                }
                sum += p[i];
            }
        }

        cout << ans << endl;
    }
}