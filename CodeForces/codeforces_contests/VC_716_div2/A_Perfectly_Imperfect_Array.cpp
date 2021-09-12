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

        bool temp = true;
        for (int i = 0; i < n; i++)
        {
            double ans = sqrt(arr[i]);
            if (ans != floor(ans))
            {
                cout << "YES" << endl;
                temp = false;
                break;
            }
        }

        if (temp)
            cout << "NO" << endl;
        // debug(t);
    }
}