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

vector<int> solve3(int n) {
    if (n % 2 == 1) return {1, n / 2, n / 2};
    if (n % 4 == 0) return {n / 2, n / 4, n / 4};
    if (n % 2 == 0) return {2, n / 2 - 1, n / 2 - 1};

    return {1};
}

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        int n, k;
        cin >> n >> k;
        vector<int> added = solve3(n - k + 3);
        for (int i = 0; i < k; ++i) {
            cout << (i < 3 ? added[i] : 1) << ' ';  // <3
        }
        cout << '\n';
    }
    return 0;
}