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

        int arr[2 * n];
        for (int i = 0; i < 2 * n; i++)
            cin >> arr[i];

        sort(arr, arr + (2 * n));
        int i = 0, j = (2 * n) - 1;
        while (i < n && j >= n)
        {
            cout << arr[i++] << " " << arr[j--] << " ";
        }
        cout << endl;
    }
}