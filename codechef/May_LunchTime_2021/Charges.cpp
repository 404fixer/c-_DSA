#include <bits/stdc++.h>
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
        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;
        int arr[k];
        for (int i = 0; i < k; i++)
            cin >> arr[i];

        int dis[n];
        int total = 0;
        for (int i = 1; i < n; i++)
        {
            if (str[i] == str[i - 1])
            {
                total += 2;
            }
            else
            {
                total += 1;
            }
        }
        // debug(total);

        for (int i = 0; i < k; i++)
        {
            if (n == 1)
                total = 0;
            else if (arr[i] == 1)
            {
                if (str[arr[i] - 1] != str[arr[i]])
                {
                    total -= 1;
                    total += 2;
                }
                else
                {
                    total -= 2;
                    total += 1;
                }
            }
            else if (arr[i] == n)
            {
                if (str[arr[i] - 1] != str[arr[i] - 2])
                {
                    total -= 1;
                    total += 2;
                }
                else
                {
                    total -= 2;
                    total += 1;
                }
            }
            else
            {
                if (str[arr[i] - 1] == str[arr[i] - 2])
                {
                    total -= 2;
                    total += 1;
                }
                else
                {
                    total -= 1;
                    total += 2;
                }

                if (str[arr[i] - 1] == str[arr[i]])
                {
                    total -= 2;
                    total += 1;
                }
                else
                {
                    total -= 1;
                    total += 2;
                }
            }
            if (str[arr[i] - 1] == '0')
            {
                str[arr[i] - 1] = '1';
            }
            else
                str[arr[i] - 1] = '0';

            cout << total << endl;
        }
    }
}