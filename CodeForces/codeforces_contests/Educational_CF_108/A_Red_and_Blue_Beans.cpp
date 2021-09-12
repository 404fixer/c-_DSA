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
        long long r, b, d;
        cin >> r >> b >> d;

        long long temp_min = min(r, b);
        long long temp_max = max(r, b);

        if (temp_max > (temp_min * (d + 1)))
            cout << "no" << endl;
        else
            cout << "yes" << endl;
    }
}