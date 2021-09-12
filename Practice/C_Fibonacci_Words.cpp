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

    string str;
    cin >> str;

    bool ans = true;
    for (int i = 2; i < str.length(); i++) {
        if ((((((int)str[i - 2] - 65) + ((int)str[i - 1] - 65)) % 26)) !=
            ((int)str[i] - 65)) {
            // cout << str[i] << endl;
            cout << "NO" << endl;
            ans = false;
            break;
        }
    }
    if (ans) cout << "YES" << endl;
}