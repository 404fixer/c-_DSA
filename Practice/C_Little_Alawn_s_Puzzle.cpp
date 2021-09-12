#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define mod 1000000007
#define debug(x) cout << #x << " " << x << endl;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        int arr2[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        for (int i = 0; i < n; i++) cin >> arr2[i];
        map<int, int> m;
        vector<bool> visited(n + 1, false);
        for (int i = 0; i < n; i++) {
            m.insert({arr[i], arr2[i]});
        }

        // for (auto &itr : m) {
        //     cout << itr.first << " " << itr.second << endl;
        // }

        int cnt = 1;
        for (auto &itr : m) {
            if (!visited[itr.first]) {
                // cout << itr.first << endl;
                // debug(cnt);
                int prim = itr.first;
                int s = (m.find(itr.second))->second;
                // debug(prim);
                // debug(s);
                visited[prim] = true;
                visited[itr.second] = true;
                visited[s] = true;
                // int temp = 0;
                while (prim != s) {
                    s = (m.find(s))->second;
                    visited[s] = true;
                    // temp++;
                }
                cnt = (cnt * 2) % mod;
            }
        }

        cout << cnt << endl;
    }
}