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
        long long n, m, k;
        cin >> n >> m >> k;

        if ((n * m) - 1 == k)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}