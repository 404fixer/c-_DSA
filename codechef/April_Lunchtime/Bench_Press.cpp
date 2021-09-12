#include <iostream>
#include <algorithm>
#define endl "\n"
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
        int n, w, rod;
        cin >> n >> w >> rod;

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr + n);

        if (w <= rod)
            cout << "YES" << endl;
        else
        {
            w = w - rod;
            int i = n - 1;
            while (w > 0 && i >= 1)
            {
                if (arr[i] == arr[i - 1])
                {
                    w -= arr[i] * 2;
                    i -= 2;
                }
                else
                {
                    i--;
                }
            }

            if (w <= 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }

        // if (w <= rod)
        // {
        //     cout << "YES" << endl;
        // }
        // else
        // {
        //     w = w - rod;
        //     if (w % 2 == 1 && w == n)
        //     {
        //         cout << "NO" << endl;
        //     }
        //     else
        //     {
        //         if (w > n)
        //         {
        //             cout << "NO" << endl;
        //         }
        //         else
        //         {
        //             cout << "YES" << endl;
        //         }
        //     }
        // }
    }
}