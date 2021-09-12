#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

// Driver function to sort the vector elements
// by second element of pairs
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> vect;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        vect.push_back(make_pair(x, y));
        // vect[i].first = x;
        // vect[i].second = y;
    }
    // cout << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << vect[i].first << " " << vect[i].second << endl;
    // }

    sort(vect.begin(), vect.end(), sortbysec);

    int ans = 0, temp = 0;
    for (int i = 0; i < n; i++)
    {
        // cout << vect[i].first << endl;
        if (temp <= vect[i].first)
        {
            ans++;
            temp = vect[i].second;
        }
    }

    cout << ans << endl;
}