#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define mod 1000000007
#define debug(x) cout << #x << " " << x << endl;
using namespace std;

// Recursive function to return gcd of a and b
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    set<int> coprimes;
    ll prod = 1;
    for (int i = 1; i < n; i++)
    {
        if (gcd(i, n) == 1)
        {
            coprimes.insert(i);
            prod = (prod * (ll)i) % n;
        }
    }

here:;
    if (prod == (ll)1)
    {
        cout << coprimes.size() << endl;
        for (auto itr : coprimes)
            cout << itr << " ";
        cout << endl;
    }
    else
    {
        coprimes.erase(prod % (ll)n);
        prod = (prod / (prod % (ll)n));
        goto here;
    }
}
