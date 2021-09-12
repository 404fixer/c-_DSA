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

        for (int i = 0; i < n; i++)
            if (arr[i] % 2 == 1)
                cout << arr[i] << " ";

        for (int i = 0; i < n; i++)
            if (arr[i] % 2 == 0)
                cout << arr[i] << " ";

        cout << endl;
    }
}