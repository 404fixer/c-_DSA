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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int g, p, arr[11];
        cin >> g >> p;
        for (int i = 1; i < 11; i++)
            cin >> arr[i];

        ll minDays, maxDays;
        ll pat = 0;
        for (int i = 10; i >= 1; i--)
        {
            if (i > g)
            {
                pat += arr[i];
            }
        }
        ll days = pat / p;
        if (pat % p != 0)
        {
            minDays = days + 1;
            maxDays = days + (((pat % p) + arr[g]) / p);
            if (((pat % p) + arr[g]) % p != 0)
                maxDays++;
        }
        else
        {
            minDays = days + 1;
            maxDays = days + (arr[g] / p);
            if (arr[g] % p != 0)
                maxDays++;
        }

        cout << minDays << " " << maxDays << endl;
    }
}