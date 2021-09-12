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
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    bool intersect = false;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            int p = min(a[i], a[i + 1]), q = max(a[i], a[i + 1]);
            int x = min(a[j], a[j + 1]), y = max(a[j], a[j + 1]);
            if ((p < x && x < q && q < y) || (x < p && p < y && y < q))
                intersect = true;
        }
    }

    if (intersect)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}