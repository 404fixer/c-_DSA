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
#define rep1(i, a, b) for (int i = a; i >= b; i--)
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define debug(x) cout << #x << " " << x << endl;
#define mod 1000000007
const long long inf = 1e18;
using namespace std;

ll gcd(ll a, ll b) {
    if (b > a) {
        return gcd(b, a);
    }
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
ll expo(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
void google(ll t) { cout << "Case #" << t << ": "; }
#define printyes cout << "YES" << endl
#define printno cout << "NO" << endl

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin>>t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll r[n];
        vector<pair<ll, ll>> rs;
        vector<ll> uni;
        map<ll, ll> q;
        rep(i, 1, n + 1) {
            ll x;
            cin >> x;
            r[i - 1] = x;
            rs.pb({x, (ll)i});
            uni.pb(x);
        }

        sort(all(rs));
        sort(all(uni));

        rep(i, 0, k) {
            ll x, y;
            cin >> x >> y;
            if (r[x - 1] > r[y - 1]) {
                // q.insert({x, y});
                q[x]++;
            } else if (r[y - 1] > r[x - 1]) {
                // q.insert({y, x});
                q[y]++;
            }
        }

        vector<ll> ans(n);
        rep(i, 0, rs.size()) {
            ll te = 0;
            auto itr = lower_bound(all(uni), rs[i].fr);
            // auto itr = rs.begin();
            if (itr == uni.begin()) {
                te = 0;
            } else {
                // itr--;
                te += itr - uni.begin();
                // debug(i);
                // debug(te);
                // what are the indexes which are having the conflicts with
                // current index
                int curr = rs[i].sc;
                if (q.find(curr) != q.end()) {
                    te -= (q.find(curr))->sc;
                }
                // debug(te);
            }

            ans[rs[i].sc - 1] = te;
        }

        rep(i, 0, ans.size()) { cout << ans[i] << " "; }
        cout << endl;
    }
}