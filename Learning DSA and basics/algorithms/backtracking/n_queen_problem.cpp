#include <bits/stdc++.h>
using namespace std;

bool isSafe(int **arr, int x, int y, int n)
{
    for (int i = 0; i < x; i++)
    {
        if (arr[i][y] == 1)
        {
            return false;
        }
    }

    int i = x;
    for (int j = y; i >= 0 && j >= 0; j--)
    {
        if (arr[i][j] == 1)
        {
            return false;
        }
        i--;
    }

    i = x;
    for (int j = y; j < n && i >= 0; j++)
    {
        if (arr[i][j] == 1)
        {
            return false;
        }
        i--;
    }

    return true;
}

bool locateQueens(int **arr, int x, int n)
{
    if (x >= n)
    {
        return true;
    }

    for (int i = 0; i < n; i++)
    {
        if (isSafe(arr, x, i, n))
        {
            arr[x][i] = 1;
            if (locateQueens(arr, x + 1, n))
            {
                return true;
            }
            arr[x][i] = 0;
        }
    }

    return false;
}

int main()
{
    int n;
    cin >> n;

    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    if (locateQueens(arr, 0, n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "-1" << endl;
    }
}