#include <iostream>
#include <cmath>
#define endl "\n"
using namespace std;
#define modulo 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin >> n;

    long long arr[n];
    long long sum = 0;
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        sum = ((sum % modulo) + modulo) % modulo;
        // cout << "sum " << sum << endl;
    }

    long long oper;
    cin >> oper;

    long long x[oper];

    for (int i = 0; i < n; i++)
    {
        cin >> x[i];

        sum = sum + sum;
        sum = sum % modulo;

        cout << sum << endl;
    }
}