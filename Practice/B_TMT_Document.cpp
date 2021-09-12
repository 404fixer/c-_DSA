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

        deque<int> dq;
        bool isOkay = true;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == 'T')
            {
                dq.push_back(i);
            }
            else
            {
                if (dq.empty())
                {
                    cout << "NO" << endl;
                    isOkay = false;
                    break;
                }
                else
                {
                    dq.pop_front();
                }
            }
        }
        for (int i = 0; i < str.length() && isOkay; i++)
        {
            if (str[i] == 'M')
            {
                if (dq.empty() || dq.front() < i)
                {
                    cout << "NO" << endl;
                    isOkay = false;
                    break;
                }
                else
                {
                    dq.pop_front();
                }
            }
        }

        if (!dq.empty() && isOkay)
            cout << "NO" << endl;
        else if (isOkay)
            cout << "YES" << endl;
    }
}