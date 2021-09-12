#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#define endl "\n"
#define ll long long
#define MOD 1000000007
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

        string str;
        cin >> str;

        set<char> s;
        char prev;
        bool ans = true;
        for (int i = 0; i < n && i < str.length(); i++)
        {
            if (s.empty())
            {
                s.insert(str[i]);
                prev = str[i];
            }
            if (str[i] == prev)
            {
                continue;
            }
            else if (*(s.lower_bound(str[i])) == str[i])
            {
                ans = false;
                break;
            }
            else
            {
                prev = str[i];
                s.insert(str[i]);
            }
        }

        ans ? cout << "YES" << endl : cout << "NO" << endl;
    }
}