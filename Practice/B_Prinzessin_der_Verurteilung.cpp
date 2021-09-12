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
        int n;
        cin >> n;
        string str;
        cin >> str;

        bool found = true;
        char c = 'a';
        for (int i = 0; i < 26; i++)
        {
            if (str.find(c) == string::npos)
            {
                cout << c << endl;
                found = false;
                break;
            }
            c++;
        }

        c = 'a';
        for (int i = 0; i < 26 && found; i++)
        {
            char temp_char = 'a';
            for (int j = 0; j < 26; j++)
            {
                // string temp = c + temp_char;
                string temp = "";
                temp.push_back(c);
                temp.push_back(temp_char);
                if (str.find(temp) == string::npos)
                {
                    cout << temp << endl;
                    found = false;
                    break;
                }
                temp_char++;
            }
            c++;
        }

        c = 'a';
        for (int i = 0; i < 26 && found; i++)
        {
            char tem = 'a';
            for (int j = 0; j < 26 && found; j++)
            {
                char another_one = 'a';
                for (int k = 0; k < 26; k++)
                {
                    // string temp = c + tem + another_one;
                    string temp = "";
                    temp.push_back(c);
                    temp.push_back(tem);
                    temp.push_back(another_one);

                    if (str.find(temp) == string::npos)
                    {
                        cout << temp << endl;
                        found = false;
                        break;
                    }
                    another_one++;
                }
                tem++;
            }
            c++;
        }
    }
}