#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;

    set<int> nums;
    for (int i = 1; i <= n; i++)
        nums.insert(i);

    auto itr = nums.begin();
    if (n == 1)
    {
        cout << *itr << endl;
        return 0;
    }
    itr++;
    // auto temp = itr;
    while (!nums.empty())
    {
        cout << *itr << " ";
        if (nums.size() == 2)
        {
            itr++;
            if (itr == nums.end())
                itr = nums.begin();
            cout << *itr << endl;
            break;
        }
        auto temp = itr;
        itr++;
        if (itr == nums.end())
            itr = nums.begin();
        itr++;
        if (itr == nums.end())
            itr = nums.begin();

        nums.erase(temp);
    }
}