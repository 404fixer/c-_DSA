#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int idx = 0; idx < t; idx++)
    {
        string exp;
        cin >> exp;

        stack<char> brackets;

        int prefix = 0;
        int temp = 0;
        for (int i = 0; i < exp.length(); i++)
        {
            if (exp[i] == '<')
            {
                brackets.push('<');
            }
            else
            {
                if (brackets.empty())
                    break;
                else
                {
                    brackets.pop();
                    temp++;
                    if (brackets.empty())
                    {
                        prefix += temp;
                        temp = 0;
                    }
                }
            }
        }

        cout << prefix * 2 << endl;
    }
}