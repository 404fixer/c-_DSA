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
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        int w, b;
        cin >> w >> b;

        bool ans = true;

        int w_dominos = 0;
        w_dominos = min(k1, k2);
        w_dominos += (max(k1, k2) - min(k1, k2)) / 2;
        int b_dominos = 0;
        b_dominos = min(n - k1, n - k2);
        b_dominos += (max(n - k1, n - k2) - min(n - k1, n - k2)) / 2;
        // debug(w_dominos);
        // debug(b_dominos);

        if (w <= w_dominos && b <= b_dominos)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}