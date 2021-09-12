/* Program By govindtomariiit */

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

    // 4 1 7
    // 3 0 6

    int t = 1;
    cin >> t;
    while (t--) {
        ll a, b, c;
        cin >> a >> b >> c;

        ll temp = a + b + c;
        ll shots = temp / 9;
        if (temp % 9 == 0 && a >= shots && b >= shots && c >= shots)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}