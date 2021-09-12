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
        int x, y, a, b, d;
        cin >> x >> y >> a >> b >> d;

        int foodDay = x / a;
        int waterDays = y / b;
        int temp = min(foodDay, waterDays);
        if (temp >= d)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}