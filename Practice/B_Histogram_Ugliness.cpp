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
        ll arr[n + 2];
        ll sum = 0;
        arr[0] = 0;
        arr[n + 1] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        for (int i = 1; i <= n + 1; i++) {
            sum += abs(arr[i] - arr[i - 1]);
        }
        // debug(sum);

        for (int i = 1; i <= n; i++) {
            if (min(arr[i] - arr[i - 1], arr[i] - arr[i + 1]) > 0)
                sum -= min(arr[i] - arr[i - 1], arr[i] - arr[i + 1]);
        }

        cout << sum << endl;
    }
}