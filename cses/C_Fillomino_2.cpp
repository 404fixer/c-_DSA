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
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int chess[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            chess[i][j] = -1;
            if (i == j)
                chess[i][j] = arr[i];
        }
    }
    bool ans = true;
    for (int i = n - 1; i >= 0; i--)
    {
        int row = i, col = i;
        int count = 0;
        while (count != arr[i] - 1)
        {
            // cout << "here " << count << " " << arr[i] << endl;
            if (row < n - 1 && chess[row + 1][col] == -1)
            {
                chess[row + 1][col] = arr[i];
                count++;
                row++;
            }
            else if (col > 0 && chess[row][col - 1] == -1)
            {
                chess[row][col - 1] = arr[i];
                count++;
                col--;
            }
            else
            {
                ans = false;
                break;
            }
        }
    }
    if (ans)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cout << chess[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << -1 << endl;
    }
}