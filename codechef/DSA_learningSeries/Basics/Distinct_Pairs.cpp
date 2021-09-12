// 1, 10, 100
// 3, 4

// 2 3
// 4 5

//if these two arrays are sorted then,
//it'll become an increasing function

#include <iostream>
#include <set>
#include <utility>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //make a set of pairs
    // storing the value and index of the num
    int n, m;
    cin >> n >> m;

    set<pair<long long int, int>> a;
    set<pair<long long int, int>> b;
    long long int value;

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        a.insert(make_pair(value, i));
    }
    for (int i = 0; i < m; i++)
    {
        cin >> value;
        b.insert(make_pair(value, i));
    }

    bool temp = true;
    int idx;

    for (auto x : a)
    {
        if (temp)
        {
            for (auto y : b)
            {
                cout << x.second << " " << y.second << "\n";
                idx = y.second;
            }
            temp = false;
        }
        else
        {
            cout << x.second << " " << idx << "\n";
        }
    }
    return 0;
}