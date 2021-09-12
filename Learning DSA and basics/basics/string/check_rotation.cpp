#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

bool checkRotation(string s1, string s2)
{
    if (s1.length() == s2.length())
    {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        if(s1 == s2) {
            return true;
        } else {
            return false;
        }
    }

    return false;
}

int main()
{
    string str1, str2;

    cin >> str1 >> str2;

    cout << checkRotation(str1, str2) << endl;
}