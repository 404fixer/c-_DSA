/* Program By govindtomariiit */

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define ld long double
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
    // cin>>t;
    while (t--) {
        ll a, b;
        cin >> a >> b;

        ll two_a = 0, two_b = 0;
        ll temp = a, temp2 = b;
        while (temp % 2 == 0) {
            two_a++;
            temp /= 2;
        }
        while (temp2 % 2 == 0) {
            two_b++;
            temp2 /= 2;
        }

        ll three_a = 0, th_b = 0;
        // temp = a, temp2 = b;
        while (temp % 3 == 0) {
            three_a++;
            temp /= 3;
        }
        while (temp2 % 3 == 0) {
            th_b++;
            temp2 /= 3;
        }

        ll fi_a = 0, fi_b = 0;
        // temp = a, temp2 = b;
        while (temp % 5 == 0) {
            fi_a++;
            temp /= 5;
        }
        while (temp2 % 5 == 0) {
            fi_b++;
            temp2 /= 5;
        }

        if (temp != temp2)
            cout << -1 << endl;
        else {
            ll ans =
                abs(two_a - two_b) + abs(three_a - th_b) + abs(fi_a - fi_b);
            cout << ans << endl;
        }
    }
}