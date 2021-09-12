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
        ll arr[n + 2];
        for (int i = 0; i < n + 2; i++)
            cin >> arr[i];

        sort(arr, arr + (n + 2));
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }

        if (sum == arr[n] || sum == arr[n + 1])
        {
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
        else if (sum > arr[n + 1])
            cout << -1 << endl;
        else
        {
            for (int i = 0; i < n; i++)
            {
                sum -= arr[i];
                sum += arr[n];
                if (sum == arr[n + 1])
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (i == j)
                        {
                            cout << arr[n] << " ";
                            continue;
                        }
                        cout << arr[j] << " ";
                    }
                    cout << endl;
                    break;
                }
                else
                {
                    sum -= arr[n];
                    sum += arr[i];
                }

                if (i == n - 1)
                    cout << -1 << endl;
            }
        }
    }
}