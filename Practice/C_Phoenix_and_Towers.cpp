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
        int n, m, x;
        cin >> n >> m >> x;

        int h[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> h[i];

        multiset<pair<int, int>> towers;
        cout << "YES" << endl;
        for (int i = 1; i <= m; i++)
        {
            cout << i << " ";
            towers.insert(make_pair(h[i], i));
        }

        for (int i = m + 1; i <= n; i++)
        {
            auto itr = towers.begin();
            cout << itr->second << " ";
            towers.insert(make_pair((itr->first + h[i]), itr->second));
            towers.erase(itr);
        }
        cout << endl;
    }
}