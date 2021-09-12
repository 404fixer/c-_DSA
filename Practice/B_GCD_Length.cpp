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
        ll a, b, c;
        cin >> a >> b >> c;

        ll X = pow(10, a - 1);
        ll temp = b - c;
        ll Y = 1;
        while (temp--)
        {
            Y = Y * (ll)10 + (ll)1;
        }
        Y *= pow(10, c - 1);

        cout << X << " " << Y << endl;
    }
}