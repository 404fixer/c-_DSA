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
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string str;
        cin >> str;

        if (str[0] == '1' && str[n - 1] == '1') {
            // even number of open brackets
            int o = 0, z = 0;
            rep(i, 0, n) {
                if (str[i] == '0')
                    z++;
                else
                    o++;
            }

            if (z % 2 == 0) {
                string ans1;
                string ans2;
                int temp_o = 0, temp_z = 0;
                rep(i, 0, n) {
                    if (str[i] == '1') {
                        if (temp_o < o / 2) {
                            ans1.pb('(');
                            ans2.pb('(');
                        } else {
                            ans1.pb(')');
                            ans2.pb(')');
                        }
                        temp_o++;
                    } else {
                        if (temp_z % 2 == 0) {
                            ans1.pb('(');
                            ans2.pb(')');
                        } else {
                            ans1.pb(')');
                            ans2.pb('(');
                        }
                        temp_z++;
                    }
                }
                cout << "YES" << endl;
                cout << ans1 << endl;
                cout << ans2 << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
}