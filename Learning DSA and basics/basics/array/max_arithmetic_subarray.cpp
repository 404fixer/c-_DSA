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

    int diff = 0, length = 0, temp = 0;
    for (int i = 0; i < n - 1; i++)
    {
        diff = arr[i] - arr[i + 1];
        temp = 1;
        for (int j = i; j < n - 1; j++)
        {
            if (diff == (arr[j] - arr[j + 1]))
            {
                temp++;
            }
            else
            {
                break;
            }
        }
        if (temp > length)
        {
            length = temp;
        }
    }

    cout << length << endl;
}

// Above approach was mine
// More productive approach below :-

// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     int ans = 2;
//     int pd = arr[1] - arr[0];
//     int j = 2;
//     int curr = 2;
//     while (j < n)
//     {
//         if (arr[j] - arr[j - 1] == pd)
//         {
//             curr++;
//         }
//         else
//         {
//             pd = arr[j] - arr[j - 1];
//             curr = 2;
//         }
//         ans = max(ans, curr);
//         j++;
//     }

//     cout << ans << endl;
//     return O;
// }