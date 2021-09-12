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

        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '*')
            {
                v.push_back(i);
            }
        }

        // cout << v.size() / 2 << endl;
        int med = (int)(v.size()) / 2;
        // debug(med);

        if (!v.empty())
            med = v[med];
        // debug(med);

        ll steps = 0;
        bool some = false;
        int star = 0;

        for (int i = med; i >= 0; i--)
        {
            if (str[i] == '.')
            {
                star++;
            }
            else
            {
                steps += star;
            }
        }

        star = 0;
        for (int i = med; i < n; i++)
        {
            if (str[i] == '.')
            {
                star++;
            }
            else
            {
                steps += star;
            }
        }

        cout << steps << endl;
    }
}