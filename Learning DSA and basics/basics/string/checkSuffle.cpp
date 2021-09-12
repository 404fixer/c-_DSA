#include <bits/stdc++.h>
#include <string>
#include <typeinfo>
using namespace std;

int main()
{
    string a, b, c;
    cin >> a >> b >> c;

    unsigned int temp = 0;
    for (int i = 0; i < a.length() && c.find(b[i]) < c.length(); i++)
    {
        if (temp <= c.find(a[i]))
        {
            temp = c.find(a[i]);
        }
        else
        {
            cout << "Not Interleaved here" << endl;
            return 0;
        }
    }

    temp = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (temp < c.find(b[i]) && c.find(b[i]) < c.length())
        {
            temp = c.find(b[i]);
        }
        else
        {
            cout << "Not Interleaved" << endl;
            return 0;
        }
    }

    cout << "OK" << endl;
}