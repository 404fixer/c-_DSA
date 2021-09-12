#include <iostream>
#include <set>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        multiset<int> stck;
        for (int i = 0; i < n; i++)
        {
            if (stck.empty() || stck.upper_bound(arr[i]) == stck.end())
            {
                stck.insert(arr[i]);
            }
            else
            {
                auto itr = stck.upper_bound(arr[i]);
                stck.erase(itr);
                stck.insert(arr[i]);
            }
        }

        cout << stck.size() << " ";
        for (auto element : stck)
            cout << element << " ";

        cout << endl;
    }
}