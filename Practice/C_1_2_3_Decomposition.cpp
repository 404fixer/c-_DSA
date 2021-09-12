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

        ll ans = 0;
        ll carry = 0;
        ll te = -1;
        while (n != 0) {
            ll d = n % 10;
            if (d == 0) {
                if (carry) {
                    if (ans < (ll)3) {
                        ll one = 0, two = 0, th = 0;
                        if (te == -1) {
                            ans = 3;
                            te = d;
                            // continue;
                        } else {
                            d = te + 10;
                            th = d / 3;
                            d -= 3 * (th);
                            two = d / 2;
                            d -= 2 * two;
                            one = d;
                            d -= d;
                            ans = max(ans, one + two + th);
                            break;
                        }
                    } else if ((ll)3 == ans) {
                        te = max(te, (ll)0);
                    }
                } else {
                    if (ans < (ll)4) {
                        ll one = 0, two = 0, th = 0;
                        if (te == -1) {
                            ans = 4;
                            te = d;
                            // continue;
                        } else {
                            d = te + 10;
                            th = d / 3;
                            d -= 3 * (th);
                            two = d / 2;
                            d -= 2 * two;
                            one = d;
                            d -= d;
                            ans = max(ans, one + two + th);
                            break;
                        }
                    } else if ((ll)4 == ans) {
                        te = max(te, (ll)0);
                    }
                }
                carry = 1;
            } else {
                ll one = 0, two = 0, th = 0;
                ll temp = d;
                if (carry) d -= 1;
                th = d / 3;
                d -= 3 * (th);
                two = d / 2;
                d -= 2 * two;
                one = d;
                d -= d;

                if (one + two + th > ans) {
                    if (te == -1) {
                        ans = one + two + th;
                        te = d;
                        // continue;
                    } else {
                        d = te + 10;
                        th = d / 3;
                        d -= 3 * (th);
                        two = d / 2;
                        d -= 2 * two;
                        one = d;
                        d -= d;
                        ans = max(ans, one + two + th);
                        break;
                    }
                } else if (one + two + th == ans) {
                    te = max(te, temp);
                }
                carry = 0;
            }

            n /= 10;
        }

        cout << ans << endl;
    }
}