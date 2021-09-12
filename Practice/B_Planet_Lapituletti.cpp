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

int h, m;

bool validChars(string str) {
    rep(i, 0, 5) {
        if (i == 2) continue;

        if (str[i] == '3' || str[i] == '4' || str[i] == '6' || str[i] == '7' ||
            str[i] == '9') {
            return false;
        }
    }

    return true;
}

bool validRef(string str) {
    str = str.substr(3, 2) + ":" + str.substr(0, 2);
    swap(str[0], str[1]);
    swap(str[3], str[4]);
    // debug(str);
    rep(i, 0, 5) {
        if (i == 2) continue;

        if (str[i] == '2')
            str[i] = '5';
        else if (str[i] == '5')
            str[i] = '2';
    }

    int hr = stoi(str.substr(0, 2));
    int mi = stoi(str.substr(3, 2));

    if (hr < h && mi < m) {
        return true;
    }
    return false;
}

string incTime(string str) {
    int hr = stoi(str.substr(0, 2));
    int mi = stoi(str.substr(3, 2));

    mi++;
    if (mi >= m) {
        mi = 0;
        hr++;
        if (hr >= h) hr = 0;
    }

    string ans = "";
    if (hr < 10) {
        ans = "0" + to_string(hr);
    } else
        ans = to_string(hr);

    ans += ":";

    if (mi < 10) {
        ans += "0" + to_string(mi);
    } else
        ans += to_string(mi);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        cin >> h >> m;
        string str;
        cin >> str;

        while (true) {
            if (validChars(str)) {
                if (validRef(str)) {
                    cout << str << endl;
                    break;
                } else {
                    str = incTime(str);
                }
            } else {
                str = incTime(str);
            }
            // debug(str);
        }
    }
}