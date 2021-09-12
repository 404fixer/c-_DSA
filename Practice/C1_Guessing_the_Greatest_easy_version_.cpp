/* Program By govindtomariiit */

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) (x).begin(), (x).end()
#define fr first
#define sc second
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define debug(x) cout << #x << " " << x << endl;
#define mod 1000000007
const long long inf = 1e18;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int l = 1, r = n;
        while (l < r) {
            cout << "? " << l << " " << r << endl;
            cout.flush();
            // cout << endl;
            int temp;
            cin >> temp;

            if (r - l == 1) {
                if (temp == r) {
                    break;
                } else {
                    l = r;
                    break;
                }
            }

            int mid = (l + r) / 2;
            cout << "? " << l << " " << mid << endl;
            cout.flush();
            // cout << endl;
            int temp2;
            cin >> temp2;
            if (temp2 == temp) {
                r = mid;
                continue;
            } else {
                l = mid;
            }

            // cout << "? " << temp << " " << r << endl;
            // // cout.flush();
            // // cout << endl;
            // int temp3;
            // cin >> temp3;
            // if (temp3 == temp) {
            //     l = temp + 1;
            //     continue;
            // }
        }

        cout << "! " << l << endl;
        cout.flush();
    }
}