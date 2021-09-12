#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    long long arr[n];
    long long sum = 0;
    long long maxNum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += (arr[i]);
        maxNum = max(maxNum, arr[i]);
    }

    if (maxNum >= (sum - maxNum))
        cout << 2 * maxNum << endl;
    else
        cout << sum << endl;
}