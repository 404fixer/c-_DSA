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
#define deb(x) cout << #x << " " << x << endl;
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
        int n, q;
        cin >> n >> q;
        string str;
        cin >> str;

        rep(i, 0, q) {
            int l, r;
            cin >> l >> r;

            bool ans = false;
            rep(k, 0, l - 1) {
                if (str[k] == str[l - 1]) {
                    ans = true;
                    break;
                }
            }

            rep(j, r, n) {
                if (str[j] == str[r - 1]) {
                    // deb(k);
                    ans = true;
                    break;
                }
            }

            if (ans)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}