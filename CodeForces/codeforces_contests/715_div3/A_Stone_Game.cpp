#include <bits/stdc++.h>
#include <math.h>

#include <cmath>
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
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];

        int min_num = INT_MAX;
        int max_num = INT_MIN;
        int min_idx = -1, max_idx = -1;
        int left = -1, right = -1, btw = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] < min_num) {
                min_num = arr[i];
                min_idx = i;
            }
            if (arr[i] > max_num) {
                max_num = arr[i];
                max_idx = i;
            }
        }
        // debug(min_idx);
        // debug(max_idx);

        btw = abs(min_idx - max_idx) - 1;
        left = min(min_idx, max_idx);
        right = n - max(min_idx, max_idx) - 1;
        // debug(left);
        // debug(right);
        // debug(btw);
        int ans;
        // cout << min(2, 3);
        ans = min(left + btw + 2, right + btw + 2);
        ans = min((left + right + 2), ans);
        cout << ans << endl;
    }
}