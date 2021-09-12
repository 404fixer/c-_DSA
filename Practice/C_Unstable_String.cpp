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
        string s;
        cin >> s;
        int x[2] = {-1, -1};

        ll ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int c = s[i] - '0';
            if (c == 0 || c == 1) {
                x[c ^ (i % 2)] = i;
            }
            int mn = min(x[0], x[1]);
            ans += (ll)(i - mn);
        }

        cout << ans << "\n";
    }
}