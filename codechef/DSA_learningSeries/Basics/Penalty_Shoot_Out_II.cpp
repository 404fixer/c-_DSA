#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int idx = 0; idx < t; idx++)
    {
        int n;
        cin >> n;

        string str;
        cin >> str;

        int a_win = 0, b_win = 0;
        int a_chancesleft = n, b_chancesleft = n;
        bool isPrinted = false;
        for (int i = 0; i < 2 * n; i++)
        {
            if (str[i] == '1' && i % 2 == 0)
            {
                a_win++;
            }
            else if (str[i] == '1' && i % 2 != 0)
            {
                b_win++;
            }
            i % 2 == 0 ? a_chancesleft-- : b_chancesleft--;

            if (((a_win - b_win) > b_chancesleft) || ((b_win - a_win) > a_chancesleft))
            {
                cout << i + 1 << endl;
                isPrinted = true;
                break;
            }
            // cout << i << " " << a_win << " " << b_win << endl;
        }

        if (!isPrinted)
        {
            cout << 2 * n << endl;
        }
    }
}