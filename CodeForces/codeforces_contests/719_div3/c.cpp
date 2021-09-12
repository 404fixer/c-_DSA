#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#define endl "\n"
#define ll long long
#define MOD 1000000007
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
        // debug(t);
        int n;
        cin >> n;

        if (n == 2)
        {
            cout << -1 << endl;
            continue;
        }

        int arr[n][n];

        int count = 1;
        for (int i = 0; i < n; i++)
        {
            arr[i][i] = count;
            count++;
        }

        //1  5  7
        //4  2  9
        //6  8  3

        for (int k = 1; k <= ((2 * n) - 2); k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i != j)
                    {
                        if (i + j == k)
                        {
                            arr[i][j] = count;
                            count++;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
}
