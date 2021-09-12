#include <iostream>
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;

        long long basic = 2050;
        long long count = 0;
        if (n % basic == 0)
        {
            long long q = n / basic;
            long long ten = 10;
            while (q != 0)
            {
                count += (q % ten);
                q = q / ten;
            }
        }
        else
            count = -1;

        cout << count << endl;
    }
}