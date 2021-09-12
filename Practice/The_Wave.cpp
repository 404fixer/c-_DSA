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

    int n, q;
    cin >> n >> q;
    vector<ll> ms;
    for (int i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        ms.push_back(temp);
    }
    sort(ms.begin(), ms.end());

    ll arr[q];
    for (int i = 0; i < q; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < q; i++) {
        auto itr = lower_bound(ms.begin(), ms.end(), arr[i]);
        if (*itr == arr[i]) {
            cout << 0 << endl;
        } else if (itr == ms.end()) {
            cout << "POSITIVE" << endl;
        } else {
            // cout << ms.end() - itr << endl;
            if ((ms.end() - itr) % 2 == 1) {
                cout << "NEGATIVE" << endl;
            } else {
                cout << "POSITIVE" << endl;
            }
        }
    }
}