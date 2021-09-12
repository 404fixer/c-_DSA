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

    int n, m;
    cin >> n >> m;
    string chess[n];
    for (int i = 0; i < n; i++) cin >> chess[i];

    bool black = true;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1)
            black = false;
        else
            black = true;
        for (int j = 0; j < m; j++) {
            if (chess[i][j] == '.') chess[i][j] = black ? 'B' : 'W';
            cout << chess[i][j];
            black = (!black);
        }
        cout << endl;
    }
}