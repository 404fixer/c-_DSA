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
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;

        int minSteps = abs(a - c) + abs(b - d);
        // debug(minSteps);
        k = k - minSteps;
        // debug(k);
        if (k % 2 == 0 && k >= 0)
            cout << "YES" << endl;
        else
        {
            cout << "NO" << endl;
        }
    }
}