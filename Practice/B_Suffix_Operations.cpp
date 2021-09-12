#include <bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define int long long
#define pb push_back
#define rep(i, n) for (int i = 0; i < n; i++)
#define fast

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        vector<pair<int, int>> v;
        rep(i, n) {
            int x;
            cin >> x;
            a.pb(x);
        }
        reverse(a.begin(), a.end());
        int ans = 0;
        rep(i, n - 1) {
            int x = abs(a[i] - a[i + 1]);
            v.pb({x, i});
            ans += x;
        }

        int ans1 = 0;
        for (int i = 0; i < n; i++) {
            int bb = i;
            int aaa = 0, bbb = 0;
            if (bb > 0)
                aaa += abs(a[bb] - a[bb - 1]), bbb += abs(a[bb] - a[bb - 1]);
            if (bb + 1 < n)
                aaa += abs(a[bb] - a[bb + 1]), bbb += abs(a[bb] - a[bb + 1]);
            if (bb > 0 and bb < n - 1) {
                aaa -= abs(a[bb + 1] - a[bb - 1]);
                bbb -= abs(a[bb + 1] - a[bb - 1]);
            }
            ans1 = max(ans1, max(aaa, bbb));
        }
        cout << ans - ans1 << endl;
    }
    return 0;
}