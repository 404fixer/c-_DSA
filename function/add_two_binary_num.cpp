#include <iostream>
#include <math.h>
using namespace std;

int reverse(int num)
{
    int ans = 0, last_digit = 0;
    while (num > 0)
    {
        last_digit = num % 10;
        ans = ans * 10 + last_digit;
        num /= 10;
    }
    return ans;
}

int sum(int m, int n)
{
    int carry = 0;
    int i;
    int sum = 0;

    for (i = 0; m > 0 && n > 0; i++)
    {
        if (m % 10 == 0 && n % 10 == 0)
        {
            sum = pow(10, i) * carry + sum;
            carry = 0;
        }
        else if ((m % 10 == 0 && n % 10 == 1) || (m % 10 == 1 && n % 10 == 0))
        {
            if (carry == 0)
            {
                sum = pow(10, i) * 1 + sum;
                carry = 0;
            }
            else
            {
                sum = pow(10, i) * 0 + sum;
                carry = 1;
            }
        }
        else
        {
            sum = pow(10, i) * carry + sum;
            carry = 1;
        }

        // cout << sum << endl;
        m /= 10;
        n /= 10;
    }

    if (carry == 1)
    {
        sum = pow(10, i) * carry + sum;
        carry = 0;
    }

    return sum;
}

int main()
{
    int m, n;
    cin >> m >> n;

    cout << sum(m, n) << endl;
}