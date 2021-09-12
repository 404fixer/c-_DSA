#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int idx = 0; idx < t; idx++)
    {
        int g;
        cin >> g;
        for (int games = 0; games < g; games++)
        {
            int i, n, q;
            cin >> i >> n >> q;
            int heads, tails;

            if (i == 1)
            {
                tails = n % 2 == 0 ? n / 2 : ((n / 2) + 1);
                heads = n - tails;
            }
            else
            {
                heads = n % 2 == 0 ? n / 2 : ((n / 2) + 1);
                tails = n - heads;
            }

            q == 1 ? cout << heads << "\n" : cout << tails << "\n";
        }
    }
}