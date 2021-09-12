#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define mod 1000000007
#define debug(x) cout << #x << " " << x << endl;
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

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
        int arr[n];
        int even = 0;
        vector<int> odd;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] % 2 == 0)
                even++;
            else
                odd.push_back(arr[i]);
        }
        // debug(even);

        ll ans = (ll)0;
        int j = 1;
        while (even != 0)
        {
            ans += (ll)(n - j);
            j++;
            even--;
        }
        // debug(ans);
        for (int i = 0; i < (odd.size()); i++)
        {
            for (int j = i + 1; j < odd.size(); j++)
            {
                // debug(arr[i]);
                // debug(arr[j]);
                if (gcd(odd[i], odd[j]) > 1)
                    ans++;
            }
        }

        cout << ans << endl;
    }
}