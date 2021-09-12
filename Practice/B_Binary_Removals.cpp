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

        bool ans = true;
        int count = 0;
        for (int i = 1; i < str.length(); i++) {
            if (count != 0 && str[i] == '0' && str[i - 1] == '0') {
                ans = false;
                break;
            }

            if (str[i] == '1' && str[i - 1] == '1' && count == 0) {
                count++;
            }
        }

        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}