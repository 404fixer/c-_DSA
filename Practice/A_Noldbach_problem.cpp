#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#define endl "\n"
#define ll long long
#define MOD 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<bool> primes(n + 1, true);
    for (int i = 2; i <= n; i++)
    {
        if (primes[i] == true)
        {
            for (int j = i * i; j <= n; j += i)
            {
                primes[j] = false;
            }
        }
    }
    // cout << "prime of 6 " << primes[6] << endl;
    int count = 0;
    for (int i = 2; i <= n; i++)
    {
        if (primes[i] == true)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (primes[j] == true)
                {
                    if (i + j + 1 <= n && primes[i + j + 1] == true)
                    {
                        // cout << i << " " << j << endl;
                        count++;
                    }
                    break;
                }
            }
        }
    }

    // cout << "count " << count << endl;
    if (count >= k)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}