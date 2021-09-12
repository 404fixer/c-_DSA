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

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        sort(arr, arr + n);
        // for (int i = 0; i < n; i++)
        //     cout << arr[i] << " ";
        // cout << endl;
        ll ans = 0;
        bool alice = true;
        for (int i = n - 1; i >= 0; i--)
        {
            if (alice)
            {
                if (arr[i] % 2 == 0)
                    ans += arr[i];
            }
            else
            {
                if (arr[i] % 2 == 1)
                    ans -= arr[i];
            }
            // debug(i);
            // debug(ans);
            alice = (!alice);
        }
        // debug(ans);
        if (ans > 0)
            cout << "Alice" << endl;
        else if (ans == 0)
            cout << "Tie" << endl;
        else
            cout << "Bob" << endl;
    }
}