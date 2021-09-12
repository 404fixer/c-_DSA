#include <iostream>
#define endl "\n"
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
        int l;
        cin >> l;

        string str;
        cin >> str;

        long long good = 0, bad = 0;
        bool found = true;
        for (int i = 0; i < l; i++)
        {
            if (str[i] == '0')
            {
                bad++;
            }
            else
            {
                good++;
            }

            if (good >= bad)
            {
                cout << "yes" << endl;
                found = false;
                break;
            }
        }

        if (found)
            cout << "no" << endl;
    }
}