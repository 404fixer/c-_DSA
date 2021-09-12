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
        ll n;
        cin >> n;
        ll arr[n], brr[n];
        rep(i, 0, n) cin >> arr[i];
        rep(i, 0, n) cin >> brr[i];

        ll total = 0;
        rep(i, 0, n) { total += arr[i] * brr[i]; }

        ll maxi = total;
        rep(i, 0, n) {
            int l = i - 1;
            int r = i + 1;

            ll temp = total;
            while (l >= 0 && r < n) {
                temp -= (arr[l] * brr[l] + arr[r] * brr[r]);
                temp += (arr[l] * brr[r] + arr[r] * brr[l]);

                maxi = max(temp, maxi);
                l--;
                r++;
            }
        }

        rep(i, 0, n) {
            int l = i;
            int r = i + 1;

            ll temp = total;
            while (l >= 0 && r < n) {
                temp -= (arr[l] * brr[l] + arr[r] * brr[r]);
                temp += (arr[l] * brr[r] + arr[r] * brr[l]);

                maxi = max(temp, maxi);
                l--;
                r++;
            }
        }

        cout << maxi << endl;
    }
}