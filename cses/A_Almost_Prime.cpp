#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> almost(n + 1, 0);
    for (int i = 2; i <= n; i++)
    {
        if (almost[i] == 0)
        {
            for (int j = i + i; j <= n; j += i)
            {
                // cout << j << " " << almost[j] << endl;
                almost[j]++;
            }
        }
    }
    // cout << "==========" << endl;
    int count = 0;
    for (int i = 0; i <= n; i++)
    {
        // cout << i << " " << almost[i] << endl;
        if (almost[i] == 2)
            count++;
    }
    cout << count << endl;
}