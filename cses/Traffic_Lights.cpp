#include <iostream>
#include <set>
#include <queue>
using namespace std;

int main()
{
    int x, n;
    cin >> x >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    set<int> lights;
    lights.insert(0);
    lights.insert(x);
    multiset<int> no_light;
    no_light.insert(x);
    for (int i = 0; i < n; i++)
    {
        auto itr = lights.lower_bound(arr[i]);

        if (arr[i] == 0 || arr[i] == x)
            no_light.insert(x);
        else
        {
            auto itr3 = itr;
            auto itr2 = no_light.lower_bound(*itr3 - *(--itr3));
            // cout << endl;
            // cout << "itr value " << *itr2 << endl;
            no_light.erase(itr2);
            no_light.insert(*itr - arr[i]);
            no_light.insert(arr[i] - *(--itr));
            lights.insert(arr[i]);
        }
        cout << *(--(no_light.end())) << " ";
    }
    cout << endl;
}