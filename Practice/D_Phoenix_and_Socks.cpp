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
        int n, l, r;
        cin >> n >> l >> r;
        multiset<int> left;
        multiset<int> right;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            if (i < l)
                left.insert(temp);
            else
                right.insert(temp);
        }

        // deleting the already existing pairs
        bool del = false;
        auto prev = left.begin();
        for (auto itr = left.begin(); itr != left.end(); itr++) {
            if (del) {
                left.erase(prev);
                del = false;
            }

            if (right.lower_bound(*itr) != right.end() &&
                *right.lower_bound(*itr) == *itr) {
                right.erase(right.lower_bound(*itr));
                prev = itr;
                del = true;
            }
        }
        if (del) {
            left.erase(prev);
            del = false;
        }

        int ans = min(left.size(), right.size());
        // debug(ans);

        if (left.size() > right.size()) {
            map<int, int> m;
            for (auto &itr : left) {
                m[itr]++;
            }
            int diff = (left.size() - right.size()) / 2;
            // debug(diff);
            for (auto &itr : m) {
                if (itr.second > 1) {
                    ans += min(diff, itr.second / 2);
                    diff -= min(diff, itr.second / 2);
                }
                if (diff == 0) break;
            }

            if (diff > 0) ans += 2 * diff;
        } else if (right.size() > left.size()) {
            map<int, int> m;
            for (auto &itr : right) {
                m[itr]++;
            }
            int diff = (right.size() - left.size()) / 2;
            for (auto &itr : m) {
                if (itr.second > 1) {
                    ans += min(diff, itr.second / 2);
                    diff -= min(diff, itr.second / 2);
                }
                if (diff == 0) break;
            }

            if (diff > 0) ans += 2 * diff;
        }

        cout << ans << endl;
    }
}