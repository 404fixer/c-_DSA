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

    string g1, g2;
    cin >> g1 >> g2;

    if (g1.length() != g2.length())
        cout << "NO" << endl;
    else {
        map<char, int> m1, m2;
        for (int i = 0; i < g1.length(); i++) {
            m1[g1[i]]++;
            m2[g2[i]]++;
        }
        if (m1.size() != m2.size())
            cout << "NO" << endl;
        else {
            auto itr = m1.begin();
            auto itr2 = m2.begin();
            while (itr != m1.end() && itr2 != m2.end()) {
                if (itr->first != itr2->first || itr2->second != itr->second) {
                    cout << "NO" << endl;
                    return 0;
                }
                itr++;
                itr2++;
            }
            int cnt = 0;
            for (int i = 0; i < g1.length(); i++) {
                if (g1[i] != g2[i]) cnt++;
            }
            if (cnt == 2)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}