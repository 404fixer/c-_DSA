#include <iostream>
#include <set>
#include <queue>
#include <climits>
#include <utility>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    set<pair<int, int>> time;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        time.insert({x, y});
    }

    int temp = 0, ans = INT_MIN;
    priority_queue<int, vector<int>, greater<int>> left;
    for (auto itr : time)
    {
        left.push(itr.second);

        temp++;
        while (!left.empty() && left.top() <= itr.first)
        {
            left.pop();
            temp--;
        }

        ans = max(temp, ans);
    }

    cout << ans << "\n";
}