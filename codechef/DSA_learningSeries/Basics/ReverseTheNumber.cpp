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

        int reversedNum = 0;
        for (int i = 0; n != 0; i++)
        {
            reversedNum = ((reversedNum * 10) + (n % 10));
            n = n / 10;
        }

        cout << reversedNum << endl;
    }
}