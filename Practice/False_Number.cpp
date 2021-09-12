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
        string str;
        cin >> str;

        if (str[0] == '1') {
            cout << str[0];
            cout << "0";
            for (int i = 1; i < str.length(); i++) {
                cout << str[i];
            }
        } else {
            cout << "1";
            for (int i = 0; i < str.length(); i++) cout << str[i];
        }
        cout << endl;
    }
}