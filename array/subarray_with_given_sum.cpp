#include <iostream>
using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int i = 0, j = 0, sum = 0;
    while (sum != s)
    {
        if (sum < s)
        {
            sum += arr[i];
            i++;
        }
        else
        {
            sum -= arr[j];
            j++;
        }
    }

    cout << j << " to " << i - 1;
}