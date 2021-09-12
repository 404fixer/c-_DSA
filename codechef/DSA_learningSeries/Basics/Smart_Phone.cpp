#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin >> n;

    long long int budgets[n];
    for (long long int i = 0; i < n; i++)
    {
        cin >> budgets[i];
    }

    sort(budgets, budgets + n);

    long long int maxRevenue = 0;
    long long int numOfPeople = n;
    for (long long int i = 0; i < n; i++)
    {
        if (maxRevenue < (budgets[i] * numOfPeople))
        {
            maxRevenue = budgets[i] * numOfPeople;
        }
        numOfPeople--;
    }

    cout << maxRevenue << endl;
}