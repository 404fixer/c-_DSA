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
        int n;
        cin >> n;
        int arr[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> arr[i];

        stack<int> dry;
        for (int i = 1; i <= n; i++)
        {
            if (arr[i] == 0)
                dry.push(i);
            else if (!dry.empty())
            {
                while (!dry.empty() && ((i - dry.top()) < arr[i]))
                {
                    dry.pop();
                }
            }
            else
            {
                continue;
            }
        }

        int ans[n + 1];
        for (int i = 1; i <= n; i++)
            ans[i] = 1;
        while (!dry.empty())
        {
            ans[dry.top()] = 0;
            dry.pop();
        }

        for (int i = 1; i <= n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}