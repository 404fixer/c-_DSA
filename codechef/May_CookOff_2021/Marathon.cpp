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
        int D, d, a, b, c;
        cin >> D >> d >> a >> b >> c;

        ll maxdis = (ll)D * (ll)d;
        if (maxdis >= (ll)42)
            cout << max(a, max(b, c)) << endl;
        else if (maxdis >= (ll)21)
            cout << max(a, b) << endl;
        else if (maxdis >= (ll)10)
            cout << a << endl;
        else
            cout << 0 << endl;
    }
}