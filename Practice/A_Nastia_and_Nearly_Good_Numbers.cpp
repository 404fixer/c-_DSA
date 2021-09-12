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
        ll a, b;
        cin >> a >> b;

        if (b == 1)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            cout << a << " " << a * b << " " << a * (b + 1) << endl;
        }
    }
}