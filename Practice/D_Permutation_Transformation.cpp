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

void solve(int l, int r, vector<int> &a, vector<int> &d, int dep) {
    if (r <= l)
        return;
    else {
        int maxi = a[l];
        int maxi_idx = l;
        rep(i, l, r) {
            if (maxi < a[i]) {
                maxi = a[i];
                maxi_idx = i;
            }
        }
        d[maxi_idx] = dep;
        solve(l, maxi_idx, a, d, dep + 1);
        solve(maxi_idx + 1, r, a, d, dep + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, 0, n) cin >> a[i];

        vector<int> d(n, 0);
        solve(0, n, a, d, 0);
        rep(i, 0, n) cout << d[i] << " ";
        cout << endl;
    }
}