#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n, p;
    cin >> m >> n >> p;

    int arr1[m][n];
    int arr2[n][p];
    int mult_matrix[m][p];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr1[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            cin >> arr2[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            int temp = 0;
            for (int k = 0; k < n; k++)
            {
                temp = temp + (arr1[i][k] * arr2[k][j]);
            }

            mult_matrix[i][j] = temp;
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            cout << mult_matrix[i][j] << " ";
        }
        cout << endl;
    }
}