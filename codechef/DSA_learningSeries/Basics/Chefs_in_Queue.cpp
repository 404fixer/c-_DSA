#include <iostream>
#include <stack>
#include <utility>
#define MODULO 1000000007
using namespace std;

int main()
{
    long long int n, k;
    cin >> n >> k;

    long long int seniority[n];
    for (long long int i = 0; i < n; i++)
    {
        cin >> seniority[i];
    }

    long long int fearfulness = 1;
    stack<pair<long long int, long long int>> seniors;
    for (long long int i = 0; i < n; i++)
    {
        if (!seniors.empty() && seniors.top().second > seniority[i])
        {
            while (!seniors.empty() && seniors.top().second > seniority[i])
            {
                fearfulness = (((((n - seniors.top().first) - (n - i)) + 1) * fearfulness) % MODULO);
                seniors.pop();
            }
        }
        if (seniority[i] != 1)
            seniors.push({i, seniority[i]});
    }

    while (!seniors.empty())
    {
        seniors.pop();
    }

    cout << fearfulness << endl;
}