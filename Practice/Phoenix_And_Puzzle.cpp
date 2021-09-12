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
        ll n;
        cin >> n;

        if (n % (ll)2 == (ll)1)
            cout << "NO" << endl;
        else
        {
            double temp = sqrt((double)n / 2);
            double temp2 = sqrt((double)n / 4);
            // debug(temp);
            // debug(temp2);
            if (temp == floor(temp) || temp2 == floor(temp2))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}