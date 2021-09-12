#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;

    vector<pair<int, int>> contests;
    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        contests.push_back(make_pair(s, e));
    }

    vector<int> v;
    for (int i = 0; i < x; i++)
    {
        int test;
        cin >> test;
        v.push_back(test);
    }

    vector<int> w;
    for (int i = 0; i < y; i++)
    {
        int test;
        cin >> test;
        w.push_back(test);
    }

    sort(v.begin(), v.end());
    sort(w.begin(), w.end());

    int t1, t2, minTime = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        auto it1 = upper_bound(v.begin(), v.end(), contests[i].first);
        if ((it1 - v.begin()) == 0)
            continue;
        t1 = v[it1 - v.begin() - 1];

        auto it2 = lower_bound(w.begin(), w.end(), contests[i].second);
        if (it2 - w.begin() > y - 1)
            continue;
        t2 = w[it2 - w.begin()];

        minTime = min(minTime, ((t2 - t1) + 1));
    }

    cout << minTime << endl;
}