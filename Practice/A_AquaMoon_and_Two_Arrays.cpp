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
        int n;
        cin >> n;
        int a[n], b[n];
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, n) cin >> b[i];

        ll sum = 0;
        vector<pii> p;
        vector<pii> neg;
        rep(i, 0, n) {
            if (a[i] - b[i] > 0) {
                p.pb({i + 1, a[i] - b[i]});
            } else if (a[i] - b[i] < 0)
                neg.pb({i + 1, abs(a[i] - b[i])});
            sum += (a[i] - b[i]);
        }

        vector<pii> ans;
        if (sum == 0) {
            int i = 0, j = 0;
            while (i != p.size() && j != neg.size()) {
                ans.pb({p[i].fr, neg[j].fr});
                if (p[i].sc == 1) {
                    if (neg[j].sc == 1) {
                        p[i].sc--;
                        neg[j].sc--;
                        i++;
                        j++;
                    } else {
                        p[i].sc--;
                        neg[j].sc--;
                        i++;
                    }
                } else if (neg[j].sc == 1) {
                    p[i].sc--;
                    neg[j].sc--;
                    j++;
                } else {
                    p[i].sc--;
                    neg[j].sc--;
                }
            }

            cout << ans.size() << endl;
            rep(k, 0, ans.size()) {
                cout << ans[k].fr << " " << ans[k].sc << endl;
            }
        } else {
            cout << -1 << endl;
        }
    }
}