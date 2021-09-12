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
        int n, x;
        cin >> n >> x;

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int l = 0, r = n - 1;
        ll sum = 0;
        sort(arr, arr + n);
        vector<int> v;
        while (l <= r)
        {
            if (sum + arr[l] == x)
            {
                if (sum + arr[r] == x)
                {
                    cout << "NO" << endl;
                    break;
                }
                v.push_back(arr[r]);
                sum += arr[r];
                r--;
            }
            else
            {
                v.push_back(arr[l]);
                sum += arr[l];
                l++;
            }
        }

        if (v.size() == n)
        {
            cout << "YES" << endl;
            for (auto itr : v)
            {
                cout << itr << " ";
            }
            cout << endl;
        }
    }
}