#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int star1 = n;
    int star2 = n;

    for (int i = 1; i <= 2 * n; i++)
    {
        for (int j = 1; j <= ((2 * n) - 1); j++)
        {
            if (j == star1 || j == star2)
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
            star1 -= 1;
            star2 += 1;
        }
        else if (i == n)
        {
            continue;
        }
        else
        {
            star1 += 1;
            star2 -= 1;
        }
    }
}