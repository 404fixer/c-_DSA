#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;

    string str2[26];
    for (int i = 0; i < str.length(); i++)
    {
        int idx = (int)str[i] - 97;
        str2[idx].push_back(str[i]);
    }

    for (int i = 0; i < str.length(); i++)
    {
        int idx = (int)str[i] - 97;
        if (str2[idx].length() != 0)
        {
            cout << str[i];
            str2[idx].clear();
        }
    }

    cout << endl;
}