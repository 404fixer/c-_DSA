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
        ll x;
        cin >> x;

        ll b = x % (ll)11;
        ll A = x - ((ll)111 * b);
        if (A >= (ll)0 && A % (ll)11 == (ll)0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}