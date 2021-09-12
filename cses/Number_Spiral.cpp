#include <iostream>
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    while (n--)
    {
        long long x, y;
        cin >> x >> y;

        long long top, num;
        if (y >= x)
        {
            if (x == 1 && y == 1)
                num = 1;
            else if (y % 2 == 1)
            {
                top = y * y;
                num = top - x + 1;
            }
            else
            {
                top = (y - 1) * (y - 1);
                num = top + x;
            }
        }
        else
        {
            if (x % 2 == 1)
            {
                top = (x - 1) * (x - 1);
                num = top + y;
            }
            else
            {
                top = x * x;
                num = top - y + 1;
            }
        }
        cout << num << endl;
    }
}