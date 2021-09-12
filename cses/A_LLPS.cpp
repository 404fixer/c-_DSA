#include <iostream>
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;

    string ans = "";
    ans += str[0];
    for (int i = 1; i < str.length(); i++)
    {
        if (str[i] > ans[0])
        {
            ans = "";
            ans += str[i];
        }
        else if (str[i] == ans[0])
            ans += str[i];
    }

    cout << ans << endl;
}