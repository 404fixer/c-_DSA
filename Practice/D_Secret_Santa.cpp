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
        int n;
        cin >> n;
        int a[n];
        rep(i, 0, n) cin >> a[i];

        int k = 0;
        map<int, int> m;
        map<int, int> mq;
        set<int> s;
        rep(i, 1, n + 1) s.insert(i);
        rep(i, 0, n) {
            if (m.empty()) {
                m.insert({a[i], i + 1});
                mq.insert({i + 1, a[i]});
                s.erase(a[i]);
            } else {
                if (m.find(a[i]) == m.end()) {
                    m.insert({a[i], i + 1});
                    mq.insert({i + 1, a[i]});
                    s.erase(a[i]);
                }
            }
        }

        // for (auto &itr : mq) {
        //     cout << itr.sc << " ";
        // }
        // cout << endl;

        rep(i, 1, n + 1) {
            if (mq.find(i) == mq.end()) {
                int te1 = *s.begin();
                int te2 = *(--s.end());

                if (te1 != i) {
                    mq.insert({i, te1});
                    s.erase(te1);
                } else if (te2 != i) {
                    mq.insert({i, te2});
                    s.erase(te2);
                } else {
                    // cout << "here" << endl;
                    mq.insert({i, a[i - 1]});
                    auto itr = m.find(a[i - 1]);
                    int temp = itr->sc;
                    itr->sc = i;
                    // debug(temp);
                    if (te1 != temp) {
                        // cout << "her" << endl;
                        mq[temp] = te1;
                        s.erase(te1);
                    } else if (te2 != temp) {
                        // cout << "her2" << endl;
                        mq[temp] = te2;
                        s.erase(te2);
                    }
                }
            }
        }

        cout << m.size() << endl;
        for (auto &itr : mq) {
            cout << itr.sc << " ";
        }
        cout << endl;
    }
}