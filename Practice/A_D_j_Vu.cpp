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
        string str;
        cin >> str;
        int n = str.length();
        int count = 0;
        for (int i = 0; i < str.length(); i++)
            if (str[i] == 'a')
                count++;

        if (count == n)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            //aabaa
            for (int i = 0; i < n; i++)
            {
                if (str[n - 1 - i] != 'a')
                {
                    cout << "a";
                    for (int j = i; j < n; j++)
                        cout << str[j];
                    break;
                }
                else
                    cout << str[i];
            }
            cout << endl;
        }
    }
}