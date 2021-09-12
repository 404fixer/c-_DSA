#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define zb(x, y) ((x) / (y) * (y))
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a[n + 1];
        int b[n + 1];
        for (int i = 1; i <= n; ++i)
            cin >> b[i];
        for (int i = 1; i <= n; ++i)
        {
            int tmp;
            cin >> tmp;
            a[b[i]].push_back(tmp);
        }
        for (int i = 1; i <= n; ++i)
        {
            sort(a[i].begin(), a[i].end(), greater<int>());
            for (int j = 1; j < a[i].size(); ++j)
                a[i][j] += a[i][j - 1];
        }
        int res[n + 1];
        for (int i = 1; i <= n; ++i)
            res[i] = 0;
        for (int i = 1; i <= n; ++i)
        {
            int tots = a[i].size();
            for (int j = 1; j <= tots; ++j)
                res[j] += a[i][zb(tots, j) - 1];
        }
        for (int i = 1; i <= n; ++i)
            cout << res[i] << ' ';
        cout << endl;
    }
}