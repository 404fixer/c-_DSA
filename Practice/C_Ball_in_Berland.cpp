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
        int a, b, k;
        cin >> a >> b >> k;
        int arr[k], brr[k];
        map<int, int> m_a;
        map<int, int> m_b;
        for (int i = 0; i < k; i++) {
            cin >> arr[i];
            m_a[arr[i]]++;
        }
        for (int i = 0; i < k; i++) {
            cin >> brr[i];
            m_b[brr[i]]++;
        }

        ll ans = 0;
        for (int i = 0; i < k; i++) {
            // debug(i);
            // debug(ans);
            ans += (ll)(k - (m_a[arr[i]] + m_b[brr[i]] - 1));
            // debug(ans);
        }

        cout << (ans / 2) << endl;
    }
}