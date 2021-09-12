#include <iostream>
#include <set>
#include <utility>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int idx = 0; idx < t; idx++)
    {
        long long n, m;
        int k;
        cin >> n >> m >> k;

        set<pair<long long, long long>> plants;
        long long x, y;
        for (int i = 0; i < k; i++)
        {
            cin >> x >> y;
            plants.insert(make_pair(x, y));
        }

        long long fences = 0;
        for (auto itr : plants)
        {
            x = itr.first;
            y = itr.second;

            if (plants.find(make_pair(--x, y)) == plants.end())
                fences++;

            x = itr.first;
            y = itr.second;

            if (plants.find(make_pair(x, --y)) == plants.end())
                fences++;

            x = itr.first;
            y = itr.second;

            if (plants.find(make_pair(++x, y)) == plants.end())
                fences++;

            x = itr.first;
            y = itr.second;

            if (plants.find(make_pair(x, ++y)) == plants.end())
                fences++;
        }

        cout << fences << endl;
    }
}