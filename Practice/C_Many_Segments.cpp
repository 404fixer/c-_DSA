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
    multimap<long double, long double> m;
    for (int i = 0; i < n; i++) {
        long double x, y, z;
        cin >> x >> y >> z;

        if (x == 1) {
            m.insert({y, z});
        } else if (x == 2) {
            m.insert({y, z - (long double)0.1});
        } else if (x == 3) {
            m.insert({y + (long double)0.1, z});
        } else {
            m.insert({y + (long double).1, z - (long double).1});
        }
    }

    ll ans = 0;
    for (auto itr = m.begin(); itr != --m.end(); itr++) {
        bool isf = true;
        for (auto itr2 = ++itr; itr2 != m.end(); itr2++) {
            if (isf) {
                itr--;
                isf = false;
            }
            long double a = itr->first;
            long double b = itr->second;
            long double c = itr2->first;
            long double d = itr2->second;

            if (a <= c && c <= b && b <= d) {
                ans++;
            } else if (c <= a && a <= d && d <= b) {
                ans++;
            } else if (a <= c && c <= d && d <= b) {
                ans++;
            } else if (c <= a && a <= b && b <= d) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}