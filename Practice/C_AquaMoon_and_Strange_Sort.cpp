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
        int n;
        cin >> n;
        int arr[n];
        vector<int> even;
        vector<int> odd;
        rep(i, 0, n) {
            cin >> arr[i];
            if (i % 2 == 0) {
                even.pb(arr[i]);
            } else
                odd.pb(arr[i]);
        }

        sort(arr, arr + n);
        sort(all(even));
        sort(all(odd));

        int e = 0, o = 0;
        bool ans = true;
        rep(i, 0, n) {
            if (i % 2 == 0) {
                if (arr[i] == even[e]) {
                    e++;
                } else {
                    ans = false;
                    break;
                }
            } else {
                if (arr[i] == odd[o]) {
                    o++;
                } else {
                    ans = false;
                    break;
                }
            }
        }

        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}