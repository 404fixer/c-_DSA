#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    long long k;
    cin >> k;

    vector<pair<long long, long long>> applicantArea;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        applicantArea.push_back(make_pair(x - k, x + k));
    }
    sort(applicantArea.begin(), applicantArea.end());

    map<long long, int> appartmentArea;
    for (int i = 0; i < m; i++)
    {
        long long x;
        cin >> x;
        appartmentArea[x]++;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto itr = appartmentArea.lower_bound(applicantArea[i].first);
        if (itr != appartmentArea.end() && (*itr).first <= applicantArea[i].second)
        {
            // cout << i << " appartment " << (*itr).first << endl;

            ans++;
            (*itr).second--;
            if ((*itr).second == 0)
                appartmentArea.erase(itr);
            if (appartmentArea.empty())
                break;
        }
    }

    cout << ans << "\n";
}