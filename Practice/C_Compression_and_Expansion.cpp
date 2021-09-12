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

void showStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

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

        stack<int> s;
        rep(i, 0, n) {
            if (a[i] == 1)
                s.push(a[i]);
            else {
                while (s.top() != a[i] - 1) {
                    s.pop();
                }
                s.pop();
                s.push(a[i]);
            }

            vector<int> v;
            while (!s.empty()) {
                v.pb(s.top());
                s.pop();
            }
            for (int i = v.size() - 1; i >= 0; i--) {
                if (i == 0)
                    cout << v[i] << endl;
                else
                    cout << v[i] << ".";

                s.push(v[i]);
            }
            // showStack(s);

            // rep(i, 0, v.size()) { s.push(v[i]); }
        }
    }
}