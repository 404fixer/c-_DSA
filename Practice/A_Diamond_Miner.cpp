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
        multiset<int> x;
        multiset<int> y;
        for (int i = 0; i < 2 * n; i++) {
            int temp, temp2;
            cin >> temp >> temp2;
            if (temp == 0)
                y.insert(abs(temp2));
            else
                x.insert(abs(temp));
        }

        double ans = 0.0;
        auto itr_x = x.begin();
        auto itr_y = y.begin();
        while (itr_x != x.end()) {
            // debug(*itr_x);
            // debug(*itr_y);
            ans += sqrt(pow(*itr_x, 2) + pow(*itr_y, 2));

            // double m = (double)*itr_x;
            // double n = (double)*itr_y;
            // ans += sqrt((1.0 * m * m) + (1.0 * n * n));

            itr_x++;
            itr_y++;
        }

        cout << fixed << setprecision(12) << ans << endl;
    }
}