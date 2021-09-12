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
        int n, m;
        cin >> n >> m;

        int x, y;
        cin >> x >> y;

        char arr[n][m];
        int arr2[n][3];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                arr2[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
                if (arr[i][j] == 'U')
                    arr2[i][0]++;
                else if (arr[i][j] == 'P')
                    arr2[i][1]++;
                else
                    arr2[i][2]++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (arr2[i][2] >= x)
                cout << 1;
            else if (arr2[i][2] == x - 1 && arr2[i][1] >= y)
                cout << 1;
            else
                cout << 0;
        }
        cout << endl;
    }
}