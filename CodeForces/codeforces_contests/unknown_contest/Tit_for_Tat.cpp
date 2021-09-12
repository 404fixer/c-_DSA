#include <iostream>
#define endl "\n"
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
        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int first = 0;
        int second = n - 1;

        while (k--)
        {
            if (arr[first] == 0)
            {
                while (true)
                {
                    if (first != second - 1)
                    {
                        first++;
                        if (arr[first] != 0)
                            break;
                    }
                    else
                    {
                        break;
                    }
                }
                if (arr[first] == 0)
                    break;
            }
            arr[first]--;
            arr[second]++;
        }

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}