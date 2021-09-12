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

// ll *arr = new ll[2000][2000];
static ll arr[2000][2000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll temp = 1;
    ll temp2 = 1;
    for (int i = 1; i < 2000; i++)
    {
        temp2 = i;
        if (i != 1)
            temp = (arr[i - 1][1] + (ll)i);
        for (int j = 1; j < 2000; j++)
        {
            arr[i][j] = temp;
            temp += temp2;
            temp2++;
        }
    }

    // for (int i = 1; i < 5; i++)
    // {
    //     for (int j = 1; j < 5; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int t;
    cin >> t;

    while (t--)
    {
        int x, y, m, n;
        cin >> x >> y >> m >> n;

        ll path = 0;
        for (int i = x; i <= m; i++)
        {
            // debug(arr[i][y]);
            path += arr[i][y];
        }
        for (int i = y + 1; i <= n; i++)
        {
            // debug(arr[m][i]);
            path += arr[m][i];
        }
        cout << path << endl;
    }
}