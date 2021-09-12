#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#define endl "\n"
#define ll long long
#define MOD 1000000007
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

        int arr[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        map<ll, ll> m;
        for (int i = 1; i <= n; i++)
        {
            arr[i] = arr[i] - i;
            m[arr[i]]++;
        }

        ll ans = 0;
        for (auto itr : m)
        {
            if (itr.second > 1)
            {
                ans += (itr.second * (itr.second - 1)) / 2;
            }
        }

        cout << ans << endl;
    }
}