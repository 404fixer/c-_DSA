#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i;
    cin >> n;

    bool found = false;
    for (i = 0; (1 << i) <= n; i++)
    {
        if (((~(1 << i)) & n) == 0)
        {
            found = true;
            break;
        }
    }

    cout << found << endl;
}

//Another approach
//  found = (n && !(n & n-1))