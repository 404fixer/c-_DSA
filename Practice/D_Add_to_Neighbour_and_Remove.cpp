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
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        ll sum = 0;
        rep(i, 0, n) {
            cin >> arr[i];
            sum += arr[i];
        }

        vector<ll> fact;
        rep(i, 1, sqrt(sum) + 1) {
            if (sum % i == 0) {
                // debug(i);
                if (sum / i == i)
                    fact.pb(i);
                else
                    fact.pb(i), fact.pb(sum / i);
            }
        }

        // sort(all(arr));
        // debug(fact.size());
        sort(all(fact));
        ll ans = 0;
        bool ok = false;
        rep(i, 0, fact.size()) {
            ll te = 0;
            // debug(fact[i]);

            rep(j, 0, n) {
                if (te + arr[j] > fact[i]) {
                    break;
                } else if (te + arr[j] < fact[i]) {
                    te += arr[j];
                } else {
                    te = 0;
                    if (j == n - 1) {
                        ans = n - (sum / fact[i]);
                        ok = true;
                    }
                }
            }
            if (ok) {
                break;
            }
        }

        cout << ans << endl;
    }
}