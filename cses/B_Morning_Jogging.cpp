#include <iostream>
#include <climits>
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
        int n, m;
        cin >> n >> m;

        int arr[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }

        multiset<pair<int, int>> temp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                temp.insert({arr[i][j], i});
            }
        }

        int ans[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans[i][j] = -1;
            }
        }

        int count = 0;
        for (auto const &x : temp)
        {
            if (count < m)
                ans[x.second][count] = x.first;
            else
            {
                for (int i = 0; i < m; i++)
                {
                    // cout << "ans " << ans[x.second][i] << " " << x.first << endl;
                    if (ans[x.second][i] == -1)
                    {
                        ans[x.second][i] = x.first;
                        break;
                    }
                }
            }

            count++;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
}