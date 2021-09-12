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
    cin >> t;
    while (t--) {
        ll n, a, b;
        cin >> n >> a >> b;
        string str;
        cin >> str;

        ll ans = 0;
        if (b >= 0) {
            ans = (a * n) + (b * n);
        } else {
            ans = (a * n);
            int zero = 0;
            int one = 0;
            int temp = 0;
            rep(i, 0, n) {
                if (str[i] == '0') {
                    if (i == 0 || str[i - 1] == '1') zero++;
                } else {
                    if (i == 0 || str[i - 1] == '0') one++;
                }
            }
            int te = min(zero + 1, one + 1);
            ans += (b * te);
        }

        cout << ans << endl;
    }
}