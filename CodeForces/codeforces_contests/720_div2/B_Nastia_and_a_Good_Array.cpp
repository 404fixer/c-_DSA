#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <climits>
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
        ll n;
        cin >> n;

        ll arr[n];
        ll largest = INT_MIN;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] > largest)
            {
                largest = arr[i];
            }
        }

        ll temp1 = (max(largest, n));
        vector<ll> v((temp1 + 1), 0);
        set<ll> v1;
        for (ll i = 2; i <= temp1; i++)
        {
            if (v[i] == 0)
            {
                v1.insert(i);
                for (ll j = i * i; j <= temp1; j += i)
                {
                    v[j] = 1;
                }
            }
        }
        for (ll i = 2; i <= temp1; i++)
        {
            if (v[i] == 0)
            {
                v1.insert(i);
            }
        }

        cout << n / 2 << endl;
        for (int i = 1; i < n; i += 2)
        {
            ll temp;
            if (i == n - 1)
            {
                temp = arr[i - 1];
            }
            else
            {
                temp = max(arr[i - 1], arr[i + 1]);
            }
            arr[i] = *(v1.upper_bound(temp));
            cout << i << " " << i + 1 << " " << arr[i - 1] << " " << arr[i] << endl;
        }
    }
}