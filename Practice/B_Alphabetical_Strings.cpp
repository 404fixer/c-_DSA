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
        string str;
        cin >> str;

        int idx = -1;
        rep(i, 0, str.length()) {
            if (str[i] == 'a') {
                idx = i;
                break;
            }
        }

        if (idx == -1) {
            cout << "NO" << endl;
        } else {
            int l = idx - 1, r = idx + 1;
            char c = 'b';
            bool ans = true;
            while (c <= 'z' && ans) {
                if (l >= 0) {
                    if (str[l] == c) {
                        c++;
                        l--;
                    } else {
                        if (r < str.length()) {
                            if (str[r] == c) {
                                c++;
                                r++;
                            } else {
                                ans = false;
                            }
                        } else {
                            ans = false;
                        }
                    }
                } else if (r < str.length()) {
                    if (str[r] == c) {
                        c++;
                        r++;
                    } else {
                        ans = false;
                        break;
                    }
                } else {
                    break;
                }
            }

            if (ans)
                cout << "YES" << endl;
            else
                cout << "NO\n";
        }
    }
}