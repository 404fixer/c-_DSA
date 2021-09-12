#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <cmath>
#include <string.h>
#include <climits>
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
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++)
            cin >> A[i];

        sort(A.begin(), A.end());
        if (n == 1)
        {
            cout << "1\n";
            continue;
        }
        if (A[1] > 0)
        {
            if (A[0] > 0)
                cout << "1\n";
            else
                cout << "2\n";
            continue;
        }
        int ans = 1;
        int mn = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            if (A[i] <= 0)
            {
                ans++;
                mn = min(mn, A[i] - A[i - 1]);
            }
            else
            {
                if (A[i] <= mn)
                    ans++;
                break;
            }
        }
        cout << ans << "\n";
    }
}