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
    string str[t];
    int ans = 0;
    for (int i = 0; i < t; i++) {
        cin >> str[i];
        if (str[i][0] == '+' || str[i][2] == '+')
            ans++;
        else
            ans--;
    }

    cout << ans << endl;
}