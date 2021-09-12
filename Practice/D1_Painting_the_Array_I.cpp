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
    int n;
    cin >> n;
    int arr[n];
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        m[arr[i]]++;
    }

    int one = 0;
    int two = 0;
    for (auto &itr : m) {
        if (itr.second == 1) {
            one++;
        } else {
            two++;
        }
    }

    debug(one);
    debug(two);
    // int both = m.size() - one;
    cout << (two * 2) + one << endl;
}