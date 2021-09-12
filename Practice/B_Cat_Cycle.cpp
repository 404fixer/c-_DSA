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
        ll n, k;
        cin >> n >> k;

        ll ans;
        if (n % 2 == 0) {
            ans = k % n == 0 ? n : k % n;
        } else {
            ll temp = n / 2;
            // ll ini = (n / 2) + 1;
            ll pos_b = k % n == 0 ? n : k % n;
            // ll temp2;
            ll temp2 = k - (temp + 1);
            // debug(temp);
            // debug(pos_b);
            // debug(k);
            ll sim_b = pos_b % n;
            if (temp2 > 0) sim_b += ((temp2 / (temp))) % n;
            // debug(sim_b);
            if (k >= temp + 1) sim_b = (sim_b + 1) % n;
            // debug(sim_b);
            if (sim_b == 0)
                ans = n;
            else
                ans = sim_b;
        }

        cout << ans << endl;
    }
}