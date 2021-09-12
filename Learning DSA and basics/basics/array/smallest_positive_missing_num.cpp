#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - temp == 1)
        {
            temp++;
            i = 0;
        }
    }

    cout << temp + 1 << endl;
}