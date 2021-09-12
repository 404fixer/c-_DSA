#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) (x).begin(), (x).end()
#define fr first
#define sc second
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define debug(x) cout << #x << " " << x << endl;
#define mod 1000000007
const long long inf = 1e18;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        int a, b, k;
        cin >> a >> b >> k;

        if (k == 0) {
            cout << "Yes" << endl;
            rep(i, 0, 2) {
                rep(j, 0, b) cout << "1";
                rep(j, 0, a) cout << "0";
                cout << endl;
            }
            continue;
        }

        b--;
        if (k > a + b - 1 || a == 0 || b == 0) {
            cout << "No" << endl;
            continue;
        }

        string x, y;
        x.pb('1');
        y.pb('0');
        a--;
        b--;
        while (k > 0) {
            if (k == 1) {
                x.pb('0');
                y.pb('1');
                // a--;
                // b--;
                k--;
                continue;
            }
            if (b > 0) {
                x.pb('1');
                y.pb('1');
                b--;
                k--;
                continue;
            }
            if (a > 0) {
                x.pb('0');
                y.pb('0');
                a--;
                k--;
                continue;
            }
        }

        cout << "Yes" << endl;
        string x_pre, y_pre;
        x_pre.pb('1');
        y_pre.pb('1');
        while (b > 0) {
            x_pre.pb('1');
            y_pre.pb('1');
            b--;
        }
        string x_suf, y_suf;
        while (a > 0) {
            x_suf.pb('0');
            y_suf.pb('0');
            a--;
        }

        cout << x_pre << x << x_suf << endl;
        cout << y_pre << y << y_suf << endl;
    }
}