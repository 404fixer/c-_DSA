#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main()
{

    int n, x, y;
    cin >> n;

    int points[100001];

    for (int i = 0; i < 100001; i++)
        points[i] = 500;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        points[x] = std::min(points[x], y);
        // cout<<points[x]<<"\n";
    }
    // cout << endl;

    points[0] = 0;
    points[100000] = 0;

    int ans = 0;
    stack<pair<int, int>> S;
    for (int x = 0; x < 100001; x++)
    {
        y = points[x];

        if (S.empty() || S.top().second < y)
        {
            // cout << "pushed " << x << " " << y << endl;
            S.push(make_pair(x, y));
        }
        else if (S.top().second > y)
        {
            while (!S.empty() && S.top().second > y)
            {
                int o_x = S.top().first;
                int o_y = S.top().second;
                S.pop();
                // cout << x << " " << S.top().first << " " << o_y << endl;
                ans = max(ans, (x - S.top().first) * o_y);
            }
            S.push(make_pair(x, y));
        }
    }
    cout << ans << "\n";
}