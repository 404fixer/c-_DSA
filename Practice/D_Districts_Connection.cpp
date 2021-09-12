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

    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        set<int> s;
        map<int, vector<int>> a;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            s.insert(x);
            a[x].push_back(i);
        }
        if ((int)s.size() == 1) {
            cout << "NO"
                 << "\n";
            continue;
        }
        cout << "YES"
             << "\n";
        vector<vector<int>> other;
        for (auto i : a) other.push_back(i.second);
        for (int i = 1; i < (int)other.size(); i++) {
            for (auto j : other[i])
                cout << other[0][0] + 1 << " " << j + 1 << "\n";
        }
        for (int i = 1; i < (int)other[0].size(); i++)
            cout << other[0][i] + 1 << " " << other[1][0] + 1 << "\n";
    }
}