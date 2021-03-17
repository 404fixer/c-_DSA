#include <iostream>
using namespace std;

int main()
{
    int n, temp;
    cin >> n;

    if (n % 2 == 0)
    {
        temp = n * 2 - 1;
    }
    else
    {
        temp = n * 2 + 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= temp; j++)
        {
            cout << i;
        }
    }
}