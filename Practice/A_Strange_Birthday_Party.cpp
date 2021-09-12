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
        int n, m;
        cin >> n >> m;
        priority_queue<int> pq;
        rep(i, 0, n) {
            int temp;
            cin >> temp;
            pq.push(temp);
        }

        vector<ll> p;
        rep(i, 0, m) {
            ll temp;
            cin >> temp;
            p.pb(temp);
        }

        int i = 0;
        ll ans = 0;
        while (!pq.empty()) {
            if (pq.top() > i + 1) {
                ans += p[i];
            } else {
                ans += p[pq.top() - 1];
            }
            pq.pop();
            i++;
        }
        cout << ans << endl;
    }
}