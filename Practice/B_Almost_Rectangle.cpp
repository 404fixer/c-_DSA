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

        char arr[n][n];
        int ff = -1, fs = -1, sf = -1, ss = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
                if (arr[i][j] == '*' && ff == -1)
                {
                    ff = i;
                    fs = j;
                }
                else if (arr[i][j] == '*' && sf == -1)
                {
                    sf = i;
                    ss = j;
                }
            }
        }
        // debug(ff);
        // debug(fs);
        // debug(sf);
        // debug(ss);

        int tf, ts, fof, fos;
        if (ff == sf)
        {
            ts = fs;
            fos = ss;
            if (ff == 0)
            {
                tf = ff + 1;
                fof = sf + 1;
            }
            else
            {
                tf = ff - 1;
                fof = sf - 1;
            }
        }
        else if (fs == ss)
        {
            tf = ff;
            fof = sf;
            if (fs == 0)
            {
                ts = fs + 1;
                fos = ss + 1;
            }
            else
            {
                ts = fs - 1;
                fos = ss - 1;
            }
        }
        else
        {
            // cout << "here" << endl;
            tf = ff;
            ts = ss;
            fof = sf;
            fos = fs;
        }
        // cout << "===================" << endl;
        // debug(tf);
        // debug(ts);
        // debug(fof);
        // debug(fos);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i == tf && j == ts) || (i == fof && j == fos))
                {
                    arr[i][j] = '*';
                }
                cout << arr[i][j];
            }
            cout << endl;
        }
    }
}