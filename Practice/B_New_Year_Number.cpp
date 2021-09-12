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
        int x;
        cin >> x;

        int d = x % 2020;
        int A = x - (d * 2021);
        if (A >= 0 && A % 2020 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}