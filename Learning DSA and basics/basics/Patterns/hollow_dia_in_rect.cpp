#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int r = n - 1;
    int star = 1;

    for (int i = 1; i <= 2 * n; i++)
    {
        for (int j = 1; j <= ((2 * n) - 1); j++)
        {
            if (j <= r)
            {
                cout << "*";
            }
            else if (j > r + star)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;

        if (i < n)
        {
            r -= 1;
            star += 2;
        }
        else if (i == n)
        {
            continue;
        }
        else
        {
            r += 1;
            star -= 2;
        }
    }
}