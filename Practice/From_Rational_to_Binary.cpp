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
        ll a, b;
        cin >> a >> b;

        bool ans = true;
        for (int i = 1; true; i++) {
            ll temp = pow(2, i);
            ll temp2 = b / temp;

            if (temp2 == 1 && b % temp == 0) {
                break;
            }

            if ((temp2) % 2 == 0) {
                continue;
            } else {
                ans = false;
                break;
            }
        }

        if (ans)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}