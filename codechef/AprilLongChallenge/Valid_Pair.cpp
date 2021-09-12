#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> socks(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> socks[i];
    }

    if (binary_search(socks.begin(), socks.end(), socks[0]))
    {
        cout << "YES\n";
    }
    else if (binary_search(socks.begin(), socks.end(), socks[1]))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}