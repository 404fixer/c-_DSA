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
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            m[arr[i]]++;
        }
        for (auto itr : m)
            if (itr.second == 1)
            {
                for (int i = 0; i < n; i++)
                {
                    if (itr.first == arr[i])
                    {
                        cout << i + 1 << endl;
                        break;
                    }
                }
                break;
            }
    }
}