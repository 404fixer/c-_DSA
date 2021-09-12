#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <cmath>
#include <string>
#include <algorithm>
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

        int zero = 0;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '0')
                zero++;
        }

        if (zero % 2 == 1)
        {
            if (zero == 1)
            {
                cout << "BOB" << endl;
            }
            else
            {
                cout << "ALICE" << endl;
            }
        }
        else
        {
            cout << "BOB" << endl;
        }
    }
}