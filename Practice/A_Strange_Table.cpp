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
        ll n, m, x;
        cin >> n >> m >> x;

        ll row = x % n;
        if (row == 0)
            row = n;

        ll col = ((x - row) / n) + 1;
        row--;
        ll new_num = (m * row) + col;
        cout << new_num << endl;
    }
}