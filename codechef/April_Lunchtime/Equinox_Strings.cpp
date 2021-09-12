#include <iostream>
#include <vector>
#include <algorithm>
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
        long long n, a, b;
        cin >> n >> a >> b;

        vector<string> str(n);
        for (int i = 0; i < n; i++)
        {
            cin >> str[i];
        }

        sort(str.begin(), str.end());
        string s = "EQUINOX";
        long long sar = 0, anu = 0;
        for (int i = 0; i < n; i++)
        {
            if (s.find(str[i][0]) != string::npos)
            {
                sar += a;
            }
            else
            {
                anu += b;
            }
        }

        if (sar > anu)
            cout << "SARTHAK" << endl;
        else if (anu > sar)
            cout << "ANURADHA" << endl;
        else
            cout << "DRAW" << endl;
    }
}