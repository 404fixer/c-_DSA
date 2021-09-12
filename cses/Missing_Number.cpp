#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 1; i <= n; i++)
    {
        m.insert(pair<int, int>(i, 0));
    }
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        m[x]++;
    }

    for (auto itr = m.begin(); itr != m.end(); itr++)
    {
        if (itr->second == 0)
        {
            cout << itr->first << "\n";
            break;
        }
    }
}