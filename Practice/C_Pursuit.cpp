/* Program By govindtomariiit */

#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define ld long double
#define pb push_back
#define int long long
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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        priority_queue<int> a, b;
        rep(i, 0, n) {
            int temp;
            cin >> temp;
            a.push(temp);
        }

        rep(i, 0, n) {
            int temp;
            cin >> temp;
            b.push(temp);
        }

        ll suma = 0, sumb = 0;
        int stages = n - (n / 4);

        multiset<int> ma, mb;

        rep(i, 0, stages) {
            suma += a.top();
            ma.insert(a.top());
            a.pop();
            sumb += b.top();
            mb.insert(b.top());
            b.pop();
        }

        if (suma >= sumb) {
            cout << 0 << endl;
            continue;
        }

        int cnt = 0;
        int te = n + 1;
        while (suma < sumb) {
            if (te % 4 == 0) {
                suma -= *ma.begin();
                ma.erase(ma.begin());
            }
            suma += 100;
            ma.insert(100);
            if (!b.empty() && te % 4 != 0) {
                sumb += b.top();
                b.pop();
            }
            cnt++;
            te++;
        }

        cout << cnt << endl;
    }
}