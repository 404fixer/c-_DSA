#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int idx = 0; idx < t; idx++)
    {
        int n;
        cin >> n;

        int s[n], v[n], p[n];
        int profit = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> s[i] >> p[i] >> v[i];
            if (profit < ((p[i] / (s[i] + 1)) * v[i]))
                profit = ((p[i] / (s[i] + 1)) * v[i]);
        }

        cout << profit << endl;
    }
}