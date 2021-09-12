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
        ll h[n];
        for (int i = 0; i < n; i++) cin >> h[i];

        sort(h, h + n);
        ll min_diff_temp = LLONG_MAX;
        ll temp;
        ll temp2;
        for (int i = 1; i < n; i++) {
            if (min_diff_temp > abs(h[i] - h[i - 1])) {
                min_diff_temp = abs(h[i] - h[i - 1]);
                temp = i - 1;
                temp2 = i;
            }
        }

        cout << h[temp] << " ";
        for (int i = temp2 + 1; i < n; i++) {
            cout << h[i] << " ";
        }
        for (int i = 0; i < n && i < temp; i++) {
            cout << h[i] << " ";
        }
        cout << h[temp2] << endl;
    }
}