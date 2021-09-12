#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define mod 1000000007
#define debug(x) cout << #x << " " << x << endl;
using namespace std;

void printLevels(vector<int> graph[], int V, int x)
{
    // array to store level of each node
    int level[V];
    bool marked[V];

    // create a queue
    queue<int> que;

    // enqueue element x
    que.push(x);

    // initialize level of source node to 0
    level[x] = 0;

    // marked it as visited
    marked[x] = true;

    // do until queue is empty
    while (!que.empty())
    {

        // get the first element of queue
        x = que.front();

        // dequeue element
        que.pop();

        // traverse neighbors of node x
        for (int i = 0; i < graph[x].size(); i++)
        {
            // b is neighbor of node x
            int b = graph[x][i];

            // if b is not marked already
            if (!marked[b])
            {

                // enqueue b in queue
                que.push(b);

                // level of b is level of x + 1
                level[b] = level[x] + 1;

                // mark b
                marked[b] = true;
            }
        }
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
            int n;
            cin >> n;

            vector<set<int>> v(n + 1);
            string s;
            cin >> s;
            int arr[n + 1];
            for (int i = 2; i <= n; i++)
            {
                cin >> arr[i];
            }

            for (int i = 2; i <= n; i++)
            {
                v[arr[i]].insert(i);
            }

            for (int i = 0; i < n; i++)
            {
            }
        }
    }