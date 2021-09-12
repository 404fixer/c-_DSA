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

string t = "abacaba";

int count(string s) {
    int cnt = 0;
    rep(i, 0, s.size() - 6) { cnt += (s.substr(i, 7) == t); }
    return cnt;
}

string made;
bool possible(string s, int pos) {
    made.clear();
    made.resize(s.size());
    rep(i, 0, s.size()) {
        if (s[i] != '?') {
            made[i] = s[i];
            continue;
        }
        if (i < pos || i > pos + 6) {
            made[i] = 'z';
            continue;
        }
        made[i] = t[i - pos];
    }
    return (count(made) == 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        bool ans = false;
        rep(i, 0, n) {
            if (possible(s, i)) {
                // debug(t);
                cout << "Yes\n" << made << "\n";
                ans = true;
                break;
            }
        }

        if (ans) continue;
        // debug(t);
        cout << "No\n";
    }
}