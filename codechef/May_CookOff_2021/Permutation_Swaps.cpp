#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <cmath>
#include <string.h>
#include <algorithm>
#define endl "\n"
#define ll long long
#define mod 1000000007
#define debug(x) cout << #x << " " << x << endl;
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
        int n;
        cin >> n;
        int a[n + 1], p[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> p[i];

        int q;
        cin >> q;
        int arr[q][3];
        for (int i = 0; i < q; i++)
        {
            cin >> arr[i][0];
            if (arr[i][0] == 1)
                continue;
            else if (arr[i][0] == 2)
                cin >> arr[i][1] >> arr[i][2];
            else
                cin >> arr[i][1];
        }

        int matrix[n + 1][n + 1];
        memset(matrix, -1, sizeof matrix);
        for (int i = 1; i <= n; i++)
            matrix[1][i] = a[i];

        int count = 1;
        bool here = false;
        int perma = 0;
        for (int i = 0; i < q; i++)
        {
            if (arr[i][0] == 1)
            {
                if (here)
                {
                    count = (count % perma);
                    count++;
                }
                else
                {
                    count++;
                    for (int i = 1; i <= n; i++)
                    {
                        matrix[count][p[i]] = matrix[count - 1][i];
                    }
                    for (int i = 1; i <= n; i++)
                    {
                        if (matrix[i][1] == -1)
                            break;
                        if (i != (count - 1) && matrix[i][1] == matrix[count - 1][1])
                        {
                            perma = count - 1;
                            here = true;
                            count = i;
                        }
                    }
                }
            }
            else if (arr[i][0] == 2)
            {
                int temp = matrix[count][arr[i][1]];
                matrix[count][arr[i][1]] = matrix[count][arr[i][2]];
                matrix[count][arr[i][2]] = temp;
            }
            else
            {
                cout << matrix[count][arr[i][1]] << endl;
            }
        }
    }
}