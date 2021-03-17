#include <iostream>
using namespace std;

int bin_to_dec(int n)
{

    int rem = 0, dec = 0, x = 1;

    while (n > 0)
    {
        rem = n % 10;
        dec = dec + (rem * x);
        x *= 2;
        n /= 10;
    }

    return dec;
}

int main()
{
    int n;
    cin >> n;

    cout << bin_to_dec(n) << endl;
}