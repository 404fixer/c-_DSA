#include <bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main()
{
    int t;
    cin >> t;

    for (int idx = 0; idx < t; idx++)
    {
        int n;
        cin >> n;

        int w[n];
        for (int i = 0; i < n; i++)
        {
            cin >> w[i];
        }

        int l[n];
        for (int i = 0; i < n; i++)
        {
            cin >> l[i];
        }

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = w[i];
        }

        int j;
        for (int i = 0; i < n - 1; i++)
        {
            int minNumIndex = i;
            for (j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[i])
                {
                    minNumIndex = j;
                }
            }
            if (minNumIndex != i)
            {
                int temp = arr[i];
                arr[i] = arr[minNumIndex];
                arr[minNumIndex] = temp;
            }
        }

        int index[n];
        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < n; k++)
            {
                if (arr[i] == w[k])
                {
                    index[k] = i;
                    break;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << index[i] << " ";
        }

        cout << endl;
    }
}