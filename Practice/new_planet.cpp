#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) (x).begin(), (x).end()
#define fr first
#define sc second
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define debug(x) cout << #x << " " << x << endl;
#define mod 1000000007
const long long inf = 1e18;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        int h, m;
        cin >> h >> m;
        string str;
        cin >> str;

        int hr_temp = stoi(str.substr(0, 2));
        int min_temp = stoi(str.substr(3, 2));
        int t = hr_temp * m + min_temp;
        while (true) {
            for (int i = 0; i < str.length(); i++) {
                int count = 0;
                if (str[i] == '0' || str[i] == '1' || str[i] == '2' ||
                    str[i] == '5' || str[i] == '8') {
                    count++;
                }
            }
        }
    }
}