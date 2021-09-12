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

        for (int i = 0; i < str.length(); i++) {
            if (i % 2 == 0) {
                if (str[i] == 'a')
                    str[i] = 'b';
                else
                    str[i] = 'a';
            } else {
                if (str[i] == 'z')
                    str[i] = 'y';
                else
                    str[i] = 'z';
            }
        }
        cout << str << endl;
    }
}