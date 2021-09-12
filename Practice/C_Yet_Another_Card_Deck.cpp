#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define mod 1000000007
#define debug(x) cout << #x << " " << x << endl;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    int arr[n + 1], queries[q];
    vector<int> ans(51, 100);
    vector<bool> visited(51, false);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (!visited[arr[i]])
        {
            visited[arr[i]] = true;
            ans[arr[i]] = i;
        }
    }
    // for (int i = 1; i < 5; i++)
    //     cout << ans[i] << " ";
    // cout << endl;

    for (int i = 0; i < q; i++)
        cin >> queries[i];

    for (int i = 0; i < q; i++)
    {
        // ans[arr[i]] position of color
        cout << ans[queries[i]] << " ";
        // now we have to make it's position 1
        for (int j = 1; j < 51; j++)
        {
            if (ans[j] < ans[queries[i]])
                ans[j]++;
        }
        ans[queries[i]] = 1;
    }
    cout << endl;
}