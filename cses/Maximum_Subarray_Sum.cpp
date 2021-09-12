#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long max_sum = INT_MIN;
    long long currSum = 0;

    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        max_sum = max(currSum, max_sum);
        if (currSum < 0)
            currSum = 0;
    }

    cout << max_sum << "\n";
}