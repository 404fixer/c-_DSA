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
        int one = 0, two = 0;
        // int arr[n];
        for (int i = 0; i < n; i++)
        {
            // cin >> arr[i];
            int x;
            cin >> x;
            if (x == 1)
                one++;
            else
                two++;
        }

        if ((one % 2 == 1) || ((one == 0) && (two % 2 == 1)))
            cout << "NO" << endl;
        else
        {

            cout << "YES" << endl;
        }
    }
}