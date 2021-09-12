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
#define debugg(x, y) cout << #x " " << x << " " << #y << " " << y << endl;
#define setPre(x)               \
    cout << fixed << showpoint; \
    cout << setprecision(x);
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
#define py cout << "YES" << endl
#define pn cout << "NO" << endl

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        map<int, int> m, ms;
        map<int, vector<int> > mst;
        rep(i, 0, n) {
            cin >> a[i];
            m[a[i]]++;
            mst[a[i]].pb(i);
        }

        stack<int> s;
        vector<int> ans(n, 0);
        rep(i, 0, n) {
            if (m[a[i]] > 0) {
                if (m[a[i]] >= k) {
                    int cnt = 1;
                    rep(j, 0, k) {
                        ans[mst[a[i]][j]] = cnt;
                        cnt++;
                    }
                    m[a[i]] = 0;
                } else {
                    if (s.size() + m[a[i]] <= k) {
                        rep(j, 0, m[a[i]]) { s.push(mst[a[i]][j]); }
                    } else {
                        rep(j, 0, m[a[i]]) {
                            s.push(mst[a[i]][j]);
                            if (s.size() == k) {
                                int cnt2 = 1;
                                while (!s.empty()) {
                                    ans[s.top()] = cnt2;
                                    s.pop();
                                    cnt2++;
                                }
                            }
                        }
                    }
                    if (s.size() == k) {
                        int cnt3 = 1;
                        while (!s.empty()) {
                            // debug(s.top());
                            ans[s.top()] = cnt3;
                            s.pop();
                            cnt3++;
                        }
                    }
                    m[a[i]] = 0;
                }
            }
        }

        rep(i, 0, n) { cout << ans[i] << " "; }
        cout << endl;
    }
}