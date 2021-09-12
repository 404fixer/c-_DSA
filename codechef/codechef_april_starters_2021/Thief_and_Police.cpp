#include <iostream>
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
        int n, m;
        cin >> n >> m;

        int x, y, a, b;
        cin >> x >> y >> a >> b;

        int moves_t = (n - x) + (m - y);
        int moves_p = max(n - a, m - b);
        if (moves_t <= moves_p)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}