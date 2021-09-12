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

        int fives = 0;

        for (int i = 5; i < n; i = i * 5)
        {
            fives += (n / i);
        }

        cout << fives << endl;
    }
}