#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int arr[n];
    vector<int> odd, even;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i & 1)
            odd.push_back(arr[i]);
        else
            even.push_back(arr[i]);
    }
    sort(arr, arr + n);
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    int o = 0, e = 0;
    bool ans = true;
    for (int i = 0; i < n; i++) {
        int ele;
        if (i & 1)
            ele = odd[o++];
        else
            ele = even[e++];
        if (arr[i] == ele) {
        } else {
            ans = false;
            break;
        }
    }
    if (!ans)
        cout << "NO";
    else
        cout << "YES";
    cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // srand(time(0));
    int t;
    // cout<<fixed<<setprecision(20);
    t = 1;
    cin >> t;
    // int tt=1;
    while (t--) {
        // cout<<"Case #"<<tt<<": ";
        solve();
        // tt++;
    }
    return 0;
}