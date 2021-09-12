#include <bits/stdc++.h>
using namespace std;

int *subarray(int arr[], int n)
{
    int *s = new int[n];
    int prevNum = 1;
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % prevNum != 0)
            count++;

        s[i] = count;
        prevNum = arr[i];
    }

    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int features[q][3];
    for (int i = 0; i < q; i++)
    {
        cin >> features[i][0];
        if (features[i][0] == 1)
        {
            cin >> features[i][1] >> features[i][2];
        }
        else
        {
            cin >> features[i][1];
        }
    }

    int *ptr = subarray(a, n);
    for (int i = 0; i < q; i++)
    {
        if (features[i][0] == 1)
        {
            a[features[i][1] - 1] = features[i][2];
            ptr = subarray(a, n);
        }
        else
        {
            int temp = *(ptr + features[i][1] - 1);
            // cout << temp << " " << features[i][1] - 1 << endl;
            for (int j = (features[i][1] - 1); j >= 0; j--)
            {
                if (temp != *(ptr + j) || j == 0)
                {
                    if (j != 0)
                        cout << j + 2 << "\n";
                    else
                        cout << j + 1 << "\n";
                    break;
                }
            }
        }
    }
}