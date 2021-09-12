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
        int q[n];
        for (int i = 0; i < n; i++) cin >> q[i];

        vector<int> mi;
        vector<int> ma;
        set<int> s_mi;
        set<int> s_ma;
        for (int i = 1; i <= n; i++) {
            s_mi.insert(i);
            s_ma.insert(i);
        }

        int max_t = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                mi.push_back(q[i]);
                ma.push_back(q[i]);
                s_mi.erase(s_mi.find(q[i]));
                s_ma.erase(s_ma.find(q[i]));
                max_t = max(max_t, q[i]);
            } else {
                if (q[i] == max_t) {
                    mi.push_back(*s_mi.begin());
                    s_mi.erase(*s_mi.begin());

                    auto itr = s_ma.lower_bound(q[i]);
                    itr--;
                    ma.push_back(*itr);
                    s_ma.erase(itr);

                } else if (q[i] > max_t) {
                    mi.push_back(q[i]);
                    ma.push_back(q[i]);
                    s_mi.erase(s_mi.find(q[i]));
                    s_ma.erase(s_ma.find(q[i]));
                    max_t = max(max_t, q[i]);
                }
            }
        }

        for (auto &itr2 : mi) {
            cout << itr2 << " ";
        }
        cout << endl;
        for (auto &itr3 : ma) {
            cout << itr3 << " ";
        }
        cout << endl;
    }
}