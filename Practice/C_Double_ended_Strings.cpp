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
        string str, str2;
        cin >> str >> str2;

        if (str.length() > str2.length())
        {
            string temp = str;
            str = str2;
            str2 = temp;
        }

        int ans = 0;
        string longestSubstr = "";
        for (int i = 0; i < str.length(); i++)
        {
            string temp = "";
            for (int j = i; j < str.length(); j++)
            {
                temp += str[j];
                if (str2.find(temp) != string::npos)
                {
                    if (temp.length() > longestSubstr.length())
                        longestSubstr = temp;
                }
            }
        }

        ans = (str.length() - longestSubstr.length()) + (str2.length() - longestSubstr.length());
        cout << ans << endl;
    }
}