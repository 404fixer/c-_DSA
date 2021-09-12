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
        int arr[4];
        for (int i = 0; i < 4; i++)
            cin >> arr[i];

        if (min(arr[0], arr[1]) > max(arr[2], arr[3]) || max(arr[0], arr[1]) < min(arr[2], arr[3]))
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}