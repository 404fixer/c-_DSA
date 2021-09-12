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
        ll n, w;
        cin >> n >> w;
        multiset<ll> m;
        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            m.insert(x);
        }

        int h = 0;
        while (!m.empty()) {
            ll temp = w;
            auto temp2 = (--m.end());
            temp -= *temp2;
            m.erase(temp2);
            bool stop = true;
            while (!m.empty() && temp != 0 && stop) {
                auto itr = m.lower_bound(temp);
                if (*itr == temp) {
                    temp -= *itr;
                    m.erase(itr);
                } else {
                    if (itr == m.begin()) {
                        stop = false;
                    } else {
                        --itr;
                        temp -= *itr;
                        m.erase(itr);
                    }
                }
            }
            h++;
        }

        cout << h << endl;
    }
}