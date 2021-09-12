#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int mod = 1000000007;
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n + 1];

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    // int pre[n+1];
    // pre[0]=0;
    // // pre[1]=arr[1];
    // for(int i=1;i<n;i++){
    //   pre[i]=pre[i-1]+arr[i];
    // }
    map<int, int> mp;
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        int j = i;
        map<int, int> mp;
        int count = 0;
        while (j <= n)
        {
            mp[arr[j]]++;
            j += k;
            count++;
        }
        int maxi = 0;
        int save;
        for (auto x : mp)
        {
            if (maxi < x.second)
            {
                maxi = x.second;
                save = x.first;
            }
            // maxi=max(maxi,x.second);
        }
        ans += (count - maxi);
    }
    cout << ans;

    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // srand(time(0));
    // for(int i=1;i<=1414213;i++){
    //   mp[i*i]=i;
    // }
    int t;
    cin >> t;
    // t=1;
    // int tt=1;
    while (t--)
    {
        // cout<<"Case #"<<tt<<": ";
        solve();
        // tt++;
    }
    return 0;
}