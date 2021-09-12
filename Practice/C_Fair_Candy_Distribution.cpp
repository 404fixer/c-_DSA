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
    // cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        multiset<pair<ll, ll>> m;
        rep(i, 0, n) {
            ll x;
            cin >> x;
            m.insert({x, (ll)i});
        }
        ll temp = 0;
        if (k >= n) {
            temp = floor((long double)k / n);
        }

        k -= temp * n;
        multiset<pair<ll, ll>> ans;
        for (auto &itr : m) {
            if (k > 0)
                ans.insert({itr.sc, temp + (ll)1});
            else
                ans.insert({itr.sc, temp});
            k--;
        }

        for (auto &itr : ans) {
            cout << itr.sc << endl;
        }
    }
}