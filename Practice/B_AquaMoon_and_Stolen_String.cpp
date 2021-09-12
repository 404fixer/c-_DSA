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
        int n, m;
        cin >> n >> m;
        string orig[n], r[n - 1];
        rep(i, 0, n) cin >> orig[i];
        rep(i, 0, n - 1) cin >> r[i];

        string ans;
        rep(i, 0, m) {
            map<char, int> ote;
            rep(j, 0, n) ote[orig[j][i]]++;

            map<char, int> temp;
            rep(j, 0, n - 1) temp[r[j][i]]++;

            auto itr1 = ote.begin();
            auto itr2 = temp.begin();
            while (itr1 != ote.end()) {
                if (itr2 == temp.end() || itr1->fr != itr2->fr ||
                    itr1->sc != itr2->sc) {
                    ans += itr1->fr;
                    break;
                }
                itr1++;
                itr2++;
            }
        }

        cout << ans << endl;
    }
}