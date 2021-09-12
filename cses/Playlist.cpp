#include <iostream>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    queue<int> id;
    map<int, int> count;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
        if (count[arr[i]] == 1)
        {
            id.push(arr[i]);
            if (ans < id.size())
            {
                ans = id.size();
                // cout << "idx " << i << " " << ans << endl;
            }
        }
        else
        {
            while (id.front() != arr[i])
            {
                count[id.front()]--;
                id.pop();
            }
            count[id.front()]--;
            id.pop();
            id.push(arr[i]);
        }
    }

    cout << ans << endl;
}