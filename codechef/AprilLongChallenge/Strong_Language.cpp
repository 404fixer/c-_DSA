#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        string str;
        cin >> str;

        string star(k, '*');

        int temp = 0, numStar = 0;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '*')
            {
                temp++;
                if (numStar < temp)
                    numStar = temp;
            }
            else
            {
                temp = 0;
            }
        }

        if (numStar >= k)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
}