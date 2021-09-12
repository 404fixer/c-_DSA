#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <cmath>
#include <string>
#include <algorithm>
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

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        ll arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        map<ll, ll> m;
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += m[arr[i]] * (ll)(n - i);
            m[arr[i]] += (ll)(i + 1);
        }

        cout << ans << endl;
    }
}