#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <cmath>
#include <string.h>
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

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);

        if (n == 1)
            cout << 0 << endl;
        else if (arr[0] != arr[1])
            cout << n - 1 << endl;
        else
        {
            int prev = arr[0];
            for (int i = 1; i < n; i++)
            {
                if (prev != arr[i])
                {
                    cout << n - i << endl;
                    break;
                }
                if (i == n - 1)
                {
                    cout << 0 << endl;
                }
                prev = arr[i];
            }
        }
    }
}