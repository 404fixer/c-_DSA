#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    multiset<int> tickets;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        tickets.insert(-1 * x);
    }

    int arr[m];
    for (int i = 0; i < m; i++)
        cin >> arr[i];

    int ans[m];
    for (int i = 0; i < m; i++)
    {
        auto itr = tickets.lower_bound(-1 * arr[i]);
        if (itr == tickets.end())
            ans[i] = -1;
        else
        {
            ans[i] = ((*itr) * -1);
            tickets.erase(itr);
        }
    }

    for (int i = 0; i < m; i++)
        cout << ans[i] << "\n";
}