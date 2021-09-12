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

bool pal(string str) {
    int l = 0, r = str.length() - 1;
    while (l < r) {
        if (str[l] != str[r]) return false;
        l++;
        r--;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        int l = 0, r = str.length() - 1;
        string ans;
        string lol;
        while (l < r) {
            if (str[l] == str[r]) {
                ans.pb(str[l]);
                l++;
                r--;
            } else {
                // check palindrome from beg
                int te = r;
                string s2;
                while (l < te) {
                    if (str[te] == str[l]) {
                        if (pal(str.substr(l, te - l + 1))) {
                            // cout << "here\n";
                            s2 = str.substr(l, te - l + 1);
                            break;
                        }
                    }
                    te--;
                }

                // check palindrome from end
                te = l;
                string s3;
                while (te < r) {
                    if (str[te] == str[r]) {
                        if (pal(str.substr(te, r - te + 1))) {
                            // debug(str.substr(te, r - te + 1));
                            // debug(l);
                            // debug(te);
                            // debug(r);
                            s3 = str.substr(te, r - te + 1);
                            break;
                        }
                    }
                    te++;
                }

                if (s3.length() == 0 && s2.length() == 0) {
                    ans.pb(str[l]);
                } else if (s2.length() > s3.length()) {
                    ans += s2;
                } else {
                    ans += s3;
                }

                break;
            }
            lol = ans;
            if (l == r) ans.pb(str[l]);
        }

        // debug(lol);
        rep1(j, lol.size() - 1, 0) { ans.pb(lol[j]); }
        if (ans.size() == 0) {
            ans = "";
            ans.pb(str[0]);
        }

        cout << ans << endl;
    }
}