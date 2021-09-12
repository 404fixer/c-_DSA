#include <bits/stdc++.h>
// #define endl "\n"
#define ll long long
#define mod 1000000007
#define debug(x) cout << #x << " " << x << endl;
using namespace std;

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    int n;
    // cin >> n;
    scanf("%d", &n);
    int arr[n + 2];
    arr[0] = 1e6;
    arr[n + 1] = 1e6;
    int i = 1;
    // cout << "? " << i << endl;
    printf("? %d\n", i);
    fflush(stdout);

    while (cin >> arr[i]) {
        if (i == n) break;
        i++;
        if (i <= 100 && i <= n) {
            // cout << "? " << i << endl;
            printf("? %d\n", i);
            fflush(stdout);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (arr[i] < min(arr[i - 1], arr[i + 1])) {
            // cout << "! " << i << endl;
            printf("! %d\n", i);
            fflush(stdout);
            break;
        }
    }
}