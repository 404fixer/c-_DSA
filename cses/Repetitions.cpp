#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;

    int temp = 0, max = 0;
    char prevChar = str[0];
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == prevChar)
        {
            temp++;
        }
        else
        {
            temp = 1;
        }
        if (max < temp)
            max = temp;
        prevChar = str[i];
    }

    cout << max << "\n";
}