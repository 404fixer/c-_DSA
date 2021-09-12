#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<vector<int>> vis;
int n, m;

bool check(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m || vis[x][y])
    {
        return false;
    }
    return true;
}

int dfs(int x, int y)
{
    vis[x][y] = 1;
    int ans = 1;
    for (int i = 0; i < 4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];

        if (!check(X, Y))
        {
            continue;
        }
        ans += dfs(X, Y);
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        string str[n];
        for (int i = 0; i < n; i++)
        {
            cin >> str[i];
        }

        vis.clear();
        vis.resize(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (str[i][j] == '0')
                    vis[i][j] = 1;
            }
        }

        priority_queue<int> sizes;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (check(i, j))
                {
                    sizes.push(dfs(i, j));
                }
            }
        }

        sizes.pop();
        int ans = 0;
        while (!sizes.empty())
        {
            ans += sizes.top();
            sizes.pop();
            if (sizes.empty())
                break;
            else
                sizes.pop();
        }

        cout << ans << endl;
    }
}