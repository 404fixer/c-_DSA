#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define mod 1000000007
#define debug(x) cout << #x << " " << x << endl;
using namespace std;

// Function for convertion
long double Convert(long double radian) {
    long double pi = 3.14159;
    return (radian * (180 / pi));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int a[n][2];
    int c[n][2];
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i][0] >> c[i][1];
    }

    long double temp;
    bool ans = false;
    int idx = -1;
    long double p = 3.14159;
    for (int i = 0; i < n; i++) {
        long double x, y;
        if (a[0][0] == 0) {
            if (a[0][1] > 0) {
                x = p / 2;
            } else if (a[0][1] < 0) {
                x = (3 * p) / 2;
            } else {
                x = (long double)0;
            }
        } else {
            x = (long double)a[0][1] / (long double)a[0][0];
        }

        if (c[i][0] == 0) {
            if (c[i][1] > 0) {
                y = p / 2;
            } else if (c[i][1] < 0) {
                y = (3 * p) / 2;
            } else {
                y = (long double)0;
            }
        } else {
            y = (long double)c[i][1] / (long double)c[i][0];
        }
        // debug(i);
        // debug(Convert(x));
        // debug(Convert(y));
        long double de =
            max(Convert(x), Convert(y)) - min(Convert(x), Convert(y));
        int count = 0;
        int k = i;
        for (int j = 0; j < n; j++) {
            long double x_temp, y_temp;
            if (a[j][0] == 0) {
                if (a[j][1] > 0) {
                    x_temp = p / 2;
                } else if (a[j][1] < 0) {
                    x_temp = 3 * p / 2;
                } else {
                    x_temp = 0;
                }
            } else {
                x_temp = (long double)a[j][1] / (long double)a[j][0];
            }

            if (c[k][0] == 0) {
                if (c[k][1] > 0) {
                    y_temp = p / 2;
                } else if (c[k][1] < 0) {
                    y_temp = 3 * p / 2;
                } else {
                    y_temp = 0;
                }
            } else {
                y_temp = (long double)c[k][1] / (long double)c[k][0];
            }
            // debug(j);
            // debug(k);
            // debug(x_temp);
            // debug(y_temp);

            long double de_temp = max(Convert(x_temp), Convert(y_temp)) -
                                  min(Convert(x_temp), Convert(y_temp));
            if (de_temp != de) {
                break;
            }

            count++;
            k++;
            k = (k) % n;
        }
        // debug(count);
        if (count == n) {
            ans = true;
            break;
        }
    }

    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}