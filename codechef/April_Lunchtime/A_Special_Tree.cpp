#include <iostream>
#include <set>
#define endl "\n"
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
        int n, k, a;
        cin >> n >> k >> a;

        set<int> special;
        for (int i = 0; i < k; i++)
        {
            int x;
            cin >> x;
            special.insert(x);
        }

        set<pair<int, int>> nodes;
        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            nodes.insert(make_pair(x, y));
        }

        for (int i = 1; i <= n; i++)
        {
                }
    }
}