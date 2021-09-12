#include <iostream>
using namespace std;

void sieveOfEratosthenes(int n)
{
    int primes[n + 1];
    for (int i = 0; i <= n; i++)
    {
        primes[i] = 0;
    }

    for (int i = 2; i < n; i++)
    {
        if (primes[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
            {
                primes[j] = 1;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (primes[i] == 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    sieveOfEratosthenes(n);
}