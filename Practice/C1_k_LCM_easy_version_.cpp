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
        ll n, k;
        cin >> n >> k;

        ll f, s, t;
        // if (n == (ll)3)
        // {
        //     f = (ll)1;
        //     s = (ll)1;
        //     t = (ll)1;
        // }
        // else if (n == (ll)4)
        // {
        //     f = (ll)1;
        //     s = (ll)1;
        //     t = (ll)2;
        // }
        if (n % (ll)2 == (ll)0)
        {
            if ((n / (ll)2) % (ll)2 == (ll)0)
            {
                f = (n / (ll)2);
                s = (n / (ll)4);
                t = s;
            }
            else
            {
                f = ((n / (ll)2) - (ll)1);
                s = ((n / (ll)2) - (ll)1);
                t = (ll)2;
            }
        }
        else
        {
            f = (n / (ll)2);
            s = n / (ll)2;
            t = (ll)1;
        }

        cout << f << " " << s << " " << t << endl;
    }
}