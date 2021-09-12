#include <bits/stdc++.h>
using namespace std;

bool whoWins = 0;

long long int factorial(int n)
{
    return (n == 0 || n == 1) ? (1) : (n * factorial(n - 1));
}

long long int checkNum(long long int d, int y)
{
    if (d == 1)
    {
        return 1;
    }
    int temp = 0;
    for (long long int i = 2; i <= d; i++)
    {
        int count = 0;
        for (long long int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                count++;
                break;
            }
        }
        if (count == 0 && d % i == 0)
        {
            temp++;
        }
    }

    if (temp == y)
    {
        whoWins = !whoWins;
        return d;
    }
    else
    {
        return checkNum(d--, y);
    }
}

bool primeGame(long long int d, int y)
{
    d = d - checkNum(d, y);
    if (d == 0)
    {
        return whoWins;
    }
    return primeGame(d, y);
}

int main()
{
    int t;
    cin >> t;

    for (int idx = 0; idx < t; idx++)
    {
        int x;
        int y;

        cin >> x >> y;
        long long int n = factorial(x);
        cout << n << endl;
        // if (primeGame(n, y))
        // {
        //     cout << "Divyam" << endl;
        // }
        // else
        // {
        //     cout << "Chef" << endl;
        // }
    }
}