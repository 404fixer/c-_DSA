#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int idx = 0; idx < t; idx++)
    {
        string str;
        cin >> str;

        int len = str.length();
        int letters1[27];
        int letters2[27];

        for (int i = 0; i < 27; i++)
        {
            letters1[i] = 0;
            letters2[i] = 0;
        }

        for (int i = 0; i < (len / 2); i++)
        {
            int ascii = ((int)str[i] - 96);
            letters1[ascii]++;
        }

        for (int i = (len % 2 == 0 ? len / 2 : (len / 2 + 1)); i < len; i++)
        {
            int ascii = ((int)str[i] - 96);
            letters2[ascii]++;
        }

        bool isLapindrome = true;
        for (int i = 0; i < 27; i++)
        {
            if (letters1[i] != letters2[i])
            {
                isLapindrome = false;
                break;
            }
        }

        isLapindrome ? cout << "YES" << endl : cout << "NO" << endl;
    }
}