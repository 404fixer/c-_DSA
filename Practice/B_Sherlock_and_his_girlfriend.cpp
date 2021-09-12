#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#define endl "\n"
#define ll long long
#define MOD 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> ans(n + 2, -1);
    bool isTwo = false;
    for (int i = 2; i < n + 2; i++)
    {
        if (ans[i] == -1)
        {
            ans[i] = 1;
            for (ll j = (ll)i * (ll)i; j < n + 2; j += (ll)i)
            {
                ans[j] = 2;
                isTwo = true;
            }
        }
    }

    isTwo ? cout << 2 << endl : cout << 1 << endl;
    for (int i = 2; i < n + 2; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}