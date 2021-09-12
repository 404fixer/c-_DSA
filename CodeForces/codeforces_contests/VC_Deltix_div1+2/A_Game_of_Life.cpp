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
        int m;
        cin >> n;
        cin >> m;

        string str;
        cin >> str;

        string ans = str;

        for (int j = 1; j <= n && j <= m; j++)
        {
            if (str[0] == '0' && str[1] == '1')
            {
                ans[0] = '1';
            }
            for (int i = 1; i < n; i++)
            {
                if (i == n - 1)
                {
                    if (str[i] == '0' && str[i - 1] == '1')
                        ans[i] = '1';
                }
                else if (str[i] == '0' && ((str[i - 1] == '1' && str[i + 1] == '0') || (str[i - 1] == '0' && str[i + 1] == '1')))
                {
                    ans[i] = '1';
                }
            }
            if (ans == str)
            {
                break;
            }
            str = ans;
        }

        cout << ans << endl;
    }
}