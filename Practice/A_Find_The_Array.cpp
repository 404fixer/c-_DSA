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
        int s;
        cin >> s;

        vector<int> v;
        v.pb(1);
        s -= 1;
        int curr = 1;
        while (s != 0) {
            if (curr + 2 <= s) {
                v.pb(curr + 2);
                curr += 2;
                s -= curr;
            } else if (curr + 1 <= s) {
                v.pb(curr + 1);
                curr += 1;
                s -= curr;
            } else if (curr >= s) {
                v.pb(s);
                s -= s;
                break;
            }
        }

        cout << v.size() << endl;
    }
}