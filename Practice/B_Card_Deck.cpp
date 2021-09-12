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
        int n;
        cin >> n;
        vector<int> p(n);
        rep(i, 0, n) cin >> p[i];

        vector<deque<int>> ans(n);
        vector<bool> v(n + 1, false);
        int temp = n;
        int cnt = 0;
        int temp2 = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (p[i] == n) {
                ans[cnt].pf(p[i]);
                v[n] = true;
                cnt++;
                while (true) {
                    if (v[n - 1])
                        n--;
                    else {
                        n--;
                        break;
                    }
                }
            } else {
                v[p[i]] = true;
                ans[cnt].pf(p[i]);
            }
        }

        for (auto &itr : ans) {
            for (auto &itr2 : itr) {
                cout << itr2 << " ";
            }
        }
        cout << endl;
    }
}