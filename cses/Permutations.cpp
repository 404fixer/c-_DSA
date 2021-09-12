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

    if (n == 1)
        cout << n << endl;
    else if (n <= 3)
        cout << "NO SOLUTION" << endl;
    else if (n == 4)
        cout << 3 << " " << 1 << " " << 4 << " " << 2 << endl;
    else
    {
        int i = 1;
        while (i <= n)
        {
            cout << i << " ";
            i += 2;
        }
        i = 2;
        while (i <= n)
        {
            cout << i << " ";
            i += 2;
        }
    }
}