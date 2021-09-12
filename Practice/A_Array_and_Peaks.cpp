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
        int n, k;
        cin >> n >> k;

        if (k > (n - 1) / 2)
        {
            cout << -1 << endl;
        }
        else
        {
            vector<int> arr(n, -1);
            int count = 1;
            int voids = 0;
            for (int i = 0; i < n; i += 2)
            {
                arr[i] = count;
                count++;
                if (i != 0)
                    voids++;
                if (voids == k)
                {
                    for (int j = i + 1; j < n; j++)
                    {
                        arr[j] = count;
                        count++;
                    }
                    break;
                }
            }
            for (int i = 1; i < n; i += 2)
            {
                if (arr[i] != -1)
                    break;
                arr[i] = count;
                count++;
            }
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
}