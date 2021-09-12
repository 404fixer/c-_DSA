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
        string str;
        cin >> str;

        map<char, int> m, md;
        rep(i, 0, str.size()) { m[str[i]]++; }

        md = m;
        char c = '}';
        for (auto &itr : m) {
            if (itr.sc == 1) {
                c = min(c, itr.fr);
            }
        }

        string ans;
        if (c != '}') {
            // if the freq of at least one char is 1
            ans.pb(c);
            m[c]--;
            for (auto &itr : m) {
                while (itr.sc != 0) {
                    ans.pb(itr.fr);
                    itr.sc--;
                }
            }
        } else {
            // freq of all chars are >=2
            char govi;
            bool te = true;
            bool te2 = true;
            for (auto &itr : m) {
                if (te) {
                    govi = itr.fr;
                    ans.pb(itr.fr);
                    // ans.pb(itr.fr);
                    // itr.sc--;
                    itr.sc--;
                    te = false;
                    continue;
                }
                while (itr.sc != 0) {
                    if (m[govi] != 0) {
                        ans.pb(govi);
                        ans.pb(itr.fr);
                        m[govi]--;
                    } else {
                        ans.pb(itr.fr);
                    }
                    itr.sc--;
                }
            }

            if (m[govi] != 0 && m.size() == 1) {
                while (m[govi] != 0) {
                    ans.pb(govi);
                    m[govi]--;
                }
            }

            if (m[govi] == 1 && m.size() != 1) {
                m[govi]--;
                ans.pb(govi);
            } else if (m[govi] != 0 && m.size() != 1) {
                // if the occurence of a character is more than abs(s)/2 +1
                ans.clear();
                if (md.size() == 2) {
                    // string will look like abbbbbbbaaaaaaaaa
                    ans.pb(govi);
                    md[govi]--;
                    for (auto &itr : md) {
                        if (itr.fr == govi) continue;

                        while (itr.sc--) {
                            ans.pb(itr.fr);
                        }
                    }

                    while (md[govi]--) {
                        ans.pb(govi);
                    }
                } else {
                    ans.pb(govi);
                    char uni;
                    md[govi]--;
                    int cnt_uni = 0;
                    for (auto &itr : md) {
                        if (cnt_uni == 0) {
                        } else if (cnt_uni == 1) {
                            ans.pb(itr.fr);
                            uni = itr.fr;
                            itr.sc--;
                            while (md[govi]--) {
                                ans.pb(govi);
                            }
                        } else if (cnt_uni == 2) {
                            ans.pb(itr.fr);
                            itr.sc--;
                            while (md[uni]--) {
                                ans.pb(uni);
                            }
                            while (itr.sc--) {
                                ans.pb(itr.fr);
                            }
                        } else {
                            while (itr.sc--) {
                                ans.pb(itr.fr);
                            }
                        }

                        cnt_uni++;
                    }
                }
            }
        }

        cout << ans << endl;
    }
}