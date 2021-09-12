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
        ll c[n];
        rep(i, 0, n) cin >> c[i];

        int cnt = 0;
        int ans = INT_MIN;
        multiset<ll> ms;
        int l = 0, r = 0;
        rep(i, 0, k) {
            if (ms.empty()) {
                ms.insert(c[i]);
                cnt++;
            } else {
                if (ms.find(c[i]) == ms.end()) {
                    cnt++;
                }
                ms.insert(c[i]);
            }
        }
        // debug(cnt);
        // debug(ms.size());

        ans = max(cnt, ans);

        r = k - 1;
        while (r < n) {
            // erasing the leftmost
            ll temp = c[l];
            // debug(ms.size());
            auto itr = ms.find(c[l]);
            ms.erase(itr);
            // debug(ms.size());
            if (ms.find(temp) == ms.end()) cnt--;
            l++;

            // extending from right
            r++;
            if (r == n) break;
            if (ms.find(c[r]) == ms.end()) cnt++;
            ms.insert(c[r]);

            // debug(l);
            // debug(r);
            // debug(cnt);
            ans = max(ans, cnt);
        }

        cout << ans << endl;
    }
}