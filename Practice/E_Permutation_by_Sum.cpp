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
        int n, l, r, s;
        cin >> n >> l >> r >> s;

        int k = r - l + 1;
        ll mini = (k * (k + 1)) / 2;
        ll maxi = n * (n + 1) / 2 - (n - k) * (n - k + 1) / 2;

        if (s <= maxi && s >= mini) {
                } else {
            cout << -1 << endl;
        }
    }
}