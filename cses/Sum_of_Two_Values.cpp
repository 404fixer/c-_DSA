#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr[i].first = temp;
        arr[i].second = i;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i].first << " " << arr[i].second << endl;
    // }

    sort(arr.begin(), arr.end());
    int l = 0, r = n - 1;
    bool found = false;
    while (l < r)
    {
        // cout << "values " << arr[l].first << " " << arr[r].first << endl;
        if (arr[l].first + arr[r].first == x)
        {
            found = true;
            break;
        }
        else if (arr[l].first + arr[r].first < x)
        {
            l++;
        }
        else
        {
            r--;
        }
    }

    if (found)
        cout << arr[l].second + 1 << " " << arr[r].second + 1 << "\n";
    else
        cout << "IMPOSSIBLE\n";
}