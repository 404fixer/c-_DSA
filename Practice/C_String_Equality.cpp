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
        int n, k;
        cin >> n >> k;
        string a, b;
        cin >> a >> b;

        vector<int> va(27, 0);
        vector<int> vb(27, 0);
        rep(i, 0, n) {
            va[a[i] - 'a' + 1]++;
            vb[b[i] - 'a' + 1]++;
        }

        bool ans = true;
        rep(i, 1, 27) {
            if (i == 26) {
                if (va[i] != vb[i]) ans = false;
            } else {
                if (va[i] - vb[i] < 0) {
                    ans = false;
                    break;
                } else {
                    if ((va[i] - vb[i]) % k == 0) {
                        va[i + 1] += va[i] - vb[i];
                    } else {
                        ans = false;
                        break;
                    }
                }
            }
        }

        if (ans)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}