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

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int rem[3] = {0, 0, 0};
        for (int i = 0; i < n; i++)
            rem[arr[i] % 3]++;

        // for (int i = 0; i < 3; i++)
        //     debug(rem[i]);
        int moves = 0;
        while (true)
        {
            for (int i = 0; i < 3; i++)
            {
                if (rem[i] > n / 3)
                {
                    int diff = rem[i] - (n / 3);
                    rem[(i + 1) % 3] += diff;
                    rem[i] -= diff;
                    moves += diff;
                }
            }
            if (rem[0] == rem[1] && rem[1] == rem[2])
                // if (rem[0] == n / 3 && rem[1] == n / 3 && rem[2] == n / 3)
                break;
        }

        cout << moves << endl;
    }
}