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

    int n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);
    int min_cnt = 0;
    int max_cnt = 0;
    for (int i = 0; i < n; i++)
        if (arr[0] == arr[i])
            min_cnt++;
        else
            break;

    for (int i = n - 1; i >= 0; i--)
        if (arr[i] == arr[n - 1])
            max_cnt++;
        else
            break;

    if (arr[n - 1] - arr[0] != 0)
        cout << arr[n - 1] - arr[0] << " " << ((ll)min_cnt * (ll)max_cnt)
             << endl;
    else
        cout << 0 << " " << (((ll)min_cnt * ((ll)min_cnt - (ll)1)) / (ll)2)
             << endl;
}