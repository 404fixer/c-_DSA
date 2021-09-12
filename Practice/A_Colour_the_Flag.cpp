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

    int n_temp = 50;
    int m_temp = 50;
    char f[n_temp][m_temp];
    bool red = true;
    for (int l = 0; l < n_temp; l++) {
        if (l % 2 == 1)
            red = false;
        else
            red = true;
        for (int r = 0; r < m_temp; r++) {
            if (red)
                f[l][r] = 'R';
            else
                f[l][r] = 'W';

            red = (!red);
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) cout << f[i][j];
    //     cout << endl;
    // }

    char s[n_temp][m_temp];
    red = false;
    for (int i = 0; i < n_temp; i++) {
        if (i % 2 == 1)
            red = true;
        else
            red = false;
        for (int j = 0; j < m_temp; j++) {
            if (red)
                s[i][j] = 'R';
            else
                s[i][j] = 'W';

            red = !red;
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) cout << s[i][j];
    //     cout << endl;
    // }

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        string str[n];
        for (int i = 0; i < n; i++) cin >> str[i];

        bool first = true;
        int cnt = 0;
        bool ans = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (str[i][j] == '.')
                    continue;
                else {
                    if (cnt == 0) {
                        if (str[i][j] == s[i][j]) first = false;
                        cnt++;
                    } else {
                        if (first) {
                            if (str[i][j] == f[i][j])
                                continue;
                            else {
                                ans = false;
                                break;
                            }
                        } else {
                            if (str[i][j] == s[i][j])
                                continue;
                            else {
                                ans = false;
                                break;
                            }
                        }
                    }
                }
            }
        }

        if (ans) {
            cout << "YES" << endl;
            if (first) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) cout << f[i][j];
                    cout << endl;
                }
            } else {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) cout << s[i][j];
                    cout << endl;
                }
            }
        } else {
            cout << "NO" << endl;
        }
    }
}