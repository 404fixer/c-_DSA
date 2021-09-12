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
    cin >> t;
    while (t--) {
        ll n, a, b;
        cin >> n >> a >> b;

        if (n == 1 || b == 1) {
            cout << "Yes" << endl;
            continue;
        }

        if (a == 1) {
            n -= 1;
            if (n % b == 0)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;

            continue;
        }

        bool ans = true;
        for (ll i = 0; true; i++) {
            ll temp = n - pow(a, i);
            if (temp < 0) break;
            if (temp % b == 0) {
                cout << "Yes" << endl;
                ans = false;
                break;
            }
        }
        if (ans) cout << "No" << endl;
    }
}