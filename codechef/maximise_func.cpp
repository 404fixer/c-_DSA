#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;

        long arr[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }

        long minNum = INT_MAX;
        long maxNum = INT_MIN;

        for (int j = 0; j < n; j++)
        {
            minNum = min(minNum, arr[j]);
            maxNum = max(maxNum, arr[j]);
        }

        long output = (2 * (maxNum - minNum));
        cout << output << endl;
    }
}