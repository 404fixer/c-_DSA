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
        string a, b;
        cin >> a >> b;

        vector<int> v;
        int zeros = 0, ones = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == '0')
                zeros++;
            else
                ones++;

            if (ones == zeros) v.push_back(i);
        }

        int cnt2 = 0;
        bool same = true;
        int temp = v.empty() ? 0 : v[cnt2];
        int cnt = 0;
        bool ans = true;
        int i = 0;
        for (i = 0; i < n && cnt2 != v.size(); i++) {
            // debug(i);
            temp = v[cnt2];
            if (cnt == 0) {
                if (a[i] != b[i])
                    same = false;
                else
                    same = true;
                cnt++;
            } else {
                // debug(i);
                // cout << "============" << endl;
                if (same) {
                    // cout << "same" << endl;
                    if (a[i] != b[i]) {
                        // debug(i);
                        ans = false;
                        break;
                    }
                } else {
                    // cout << "diff" << endl;
                    if (a[i] == b[i]) {
                        // debug(i);
                        ans = false;
                        break;
                    }
                }
            }

            if (temp == i) {
                cnt2++;
                if (cnt2 == v.size()) break;
                cnt = 0;
            }
        }

        if (!ans)
            cout << "NO" << endl;
        else {
            // debug(i);
            if (i == 0) {
                for (int j = 0; j < n; j++)
                    if (a[j] != b[j]) ans = false;

                if (ans)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            } else if (i == n - 1)
                cout << "YES" << endl;
            else {
                // debug(i);
                // i = v[v.size() - 1] + 1;
                if (i != 0) i++;
                for (int j = i; j < n; j++) {
                    if (a[j] != b[j]) {
                        ans = false;
                        break;
                    }
                }

                if (ans)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
        }
    }
}
