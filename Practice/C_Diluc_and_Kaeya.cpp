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
        int n;
        cin >> n;
        string str;
        cin >> str;

        map<pair<int, int>, int> freq;
        int d = 0, k = 0;
        for (int i = 0; i < n; i++) {
            if (str[i] == 'D')
                d++;
            else
                k++;

            int x = d;
            int y = k;
            int g = gcd(x, y);
            x /= g;
            y /= g;
            freq[{x, y}]++;

            cout << freq[{x, y}] << " ";
        }
        cout << endl;
    }
}