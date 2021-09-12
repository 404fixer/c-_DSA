#include <iostream>
#include <set>

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

    multiset<int> visited;
    int towers = 0;

    for (int i = 0; i < n; i++)
    {
        auto itr = visited.upper_bound(arr[i]);
        if (visited.empty() || itr == visited.end())
        {
            visited.insert(arr[i]);
            towers++;
        }
        else
        {
            visited.erase(itr);
            visited.insert(arr[i]);
        }
    }

    cout << towers << endl;
}