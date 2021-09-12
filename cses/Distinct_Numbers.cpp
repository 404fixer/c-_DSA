#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;

    map<int, int> nums;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums[x]++;
        if (nums[x] == 1)
            ans++;
    }

    cout << ans << endl;
}