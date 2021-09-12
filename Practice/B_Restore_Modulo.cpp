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
        int n;
        cin >> n;
        set<int> st;
        int a[n + 1];
        for (int i = 1; i <= n; i++) cin >> a[i];
        if (n <= 2) {
            cout << 0 << endl;
            continue;
        }
        int mx = a[1];
        for (int i = 2; i <= n; i++) {
            mx = max(mx, a[i]);
            st.insert(a[i] - a[i - 1]);
        }
        if (st.size() > 2) {
            cout << -1 << endl;
            continue;
        }
        if (st.size() == 1) {
            cout << 0 << endl;
            continue;
        }
        int a1 = *st.begin();
        st.erase(st.begin());
        int a2 = *st.begin();
        if (a1 >= 0 && a2 >= 0) {
            cout << -1 << endl;
            continue;
        }
        if (a1 <= 0 && a2 <= 0) {
            cout << -1 << endl;
            continue;
        }
        if (a1 < a2) swap(a1, a2);
        if (mx > a1 - a2) {
            cout << -1 << endl;
            continue;
        }
        cout << a1 - a2 << " " << a1 << endl;
    }
}