#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <cmath>
#include <string>
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
        ll n;
        cin >> n;

        int i = 0;
        while ((1 << i) <= n)
        {
            i++;
        }
        i--;
        cout << ((1 << i) - 1) << endl;
    }
}