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

        cout << (n / 2) * 6 << endl;
        for (int i = 0; i < (n / 2); i++)
        {
            // debug(i);
            for (int j = 0; j <= 5; j++)
            {
                if (j % 2 == 0)
                    cout << 1 << " " << i + 1 << " " << (n / 2) + (i + 1) << endl;
                else
                    cout << 2 << " " << i + 1 << " " << (n / 2) + (i + 1) << endl;
            }
        }
    }
}