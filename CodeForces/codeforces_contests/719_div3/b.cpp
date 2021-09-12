#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#define endl "\n"
#define ll long long
#define MOD 1000000007
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
        ll n;
        cin >> n;

        ll count = 0;

        ll digit = 0;
        ll temp = n;
        while (temp != 0)
        {
            temp = temp / 10;
            digit++;
        }
        // debug(digit);
        if (digit == (ll)1)
        {
            count = n;
        }
        else
        {
            count = (digit - 1) * 9;

            temp = n;
            ll rem = 0;
            while (temp != 0)
            {
                rem = temp % 10;
                temp = temp / 10;
            }

            count += rem - 1;
            string temp_str = "";
            for (int i = 0; i < digit; i++)
            {
                temp_str += to_string(rem);
            }
            ll num = stoi(temp_str);
            // debug(num);
            if (n >= num)
            {
                count++;
            }
        }

        cout << count << endl;
    }
}