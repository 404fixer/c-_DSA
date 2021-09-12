#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#define endl "\n"
#define ll long long
#define MOD 1000000007
#define debug(x) cout << #x << " " << x << endl;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        bool isSorted = true;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (i >= 1 && arr[i] < arr[i - 1])
                isSorted = false;
        }

        if (isSorted)
            cout << 0 << endl;
        else if (arr[0] == 1)
        {
            cout << 1 << endl;
        }
        else if (arr[n - 1] == 1)
        {
            if (arr[0] == n)
                cout << 3 << endl;
            else
                cout << 2 << endl;
        }
        else if (arr[0] != 1 && arr[n - 1] != 1)
        {
            if (arr[n - 1] == n)
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }
    }
}