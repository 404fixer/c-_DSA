#include <iostream>
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
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    long long moves = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] - arr[i] > 0)
        {
            moves += arr[i - 1] - arr[i];
            arr[i] = arr[i - 1];
        }
    }

    cout << moves << endl;
}