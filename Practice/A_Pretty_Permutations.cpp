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
        int arr[n + 1];
        for (int i = 1; i <= n; i++) arr[i] = i;

        for (int i = 1; i <= n; i += 2) {
            if (n % 2 == 1) {
                if (i == n) {
                    swap(arr[i], arr[i - 2]);
                } else {
                    swap(arr[i], arr[i + 1]);
                }
            } else {
                swap(arr[i], arr[i + 1]);
            }
        }

        for (int i = 1; i <= n; i++) cout << arr[i] << " ";
        cout << endl;
    }
}