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
        int k, n, m;
        cin >> k >> n >> m;
        int arr[n], brr[m];
        rep(i, 0, n) cin >> arr[i];
        rep(i, 0, m) cin >> brr[i];

        int a = 0, b = 0;
        vector<int> v;
        int ans = 0;

        while (a < n && b < m) {
            if (arr[a] == 0) {
                v.pb(arr[a]);
                a++;
                k++;
            } else if (brr[b] == 0) {
                v.pb(brr[b]);
                b++;
                k++;
            } else {
                if (arr[a] > k && brr[b] > k) {
                    ans = -1;
                    break;
                }

                if (arr[a] <= k) {
                    v.pb(arr[a]);
                    a++;
                }
                if (brr[b] <= k) {
                    v.pb(brr[b]);
                    b++;
                }
            }
        }

        if (ans == -1) {
            cout << -1 << endl;
            continue;
        }

        while (a < n) {
            if (arr[a] <= k) {
                if (arr[a] == 0) {
                    k++;
                }
                v.pb(arr[a]);
                a++;
            } else {
                ans = -1;
                break;
            }
        }

        if (ans == -1) {
            cout << -1 << endl;
            continue;
        }

        while (b < m) {
            if (brr[b] <= k) {
                if (brr[b] == 0) {
                    k++;
                }
                v.pb(brr[b]);
                b++;
            } else {
                ans = -1;
                break;
            }
        }

        if (ans == -1) {
            cout << -1 << endl;
        } else {
            for (int i = 0; i < v.size(); i++) {
                cout << v[i] << " ";
            }
            cout << endl;
        }
    }
}