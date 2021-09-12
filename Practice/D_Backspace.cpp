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
        string s, st;
        cin >> s >> st;

        map<char, int> ms, mst;
        rep(i, 0, s.size()) { ms[s[i]]++; }
        rep(i, 0, st.length()) mst[st[i]]++;

        int l = 0, cnt = 0;
        bool ans = false, te_ans = false;

        rep(i, 0, st.length()) {
            if (ms.find(st[i]) != ms.end() && ms[st[i]] >= mst[st[i]]) {
            } else {
                te_ans = true;
                break;
            }
        }

        if (te_ans) {
            // cout << "here" << endl;
            pn;
            continue;
        }

        rep(i, 0, s.size()) {
            if (st[0] == s[i]) {
                l = 1;
                if (st.length() == 1) {
                    if ((s.length() - i - 1) % 2 == 0) {
                        ans = true;
                        break;
                    } else {
                        continue;
                    }
                }
                cnt = 0;
                rep(j, i + 1, s.size()) {
                    if (st[l] == s[j]) {
                        if (cnt % 2 == 0) {
                            // debugg(i, l);
                            // debug(i);
                            // cout << "a" << endl;
                            l++;
                            cnt = 0;
                        } else {
                            // debug(i);
                            // cout << "b" << endl;
                            cnt++;
                        }
                    } else {
                        // debug(i);

                        // cout << "c" << endl;
                        cnt++;
                    }

                    if (l == st.length()) {
                        if ((s.length() - j - 1) % 2 == 0) {
                            // debug(i);

                            // cout << "d" << endl;
                            ans = true;
                            break;
                        } else {
                            // debug(i);

                            // cout << "e" << endl;
                            cnt = 1;
                            l--;
                        }
                    }
                }
            }

            if (ans) break;

            ms[s[i]]--;
            if (mst.find(s[i]) != mst.end() && ms[s[i]] < mst[s[i]]) {
                // debug(i);
                // debug(ms[s[i]]);
                ans = false;
                break;
            }
        }

        if (ans)
            py;
        else
            pn;
    }
}