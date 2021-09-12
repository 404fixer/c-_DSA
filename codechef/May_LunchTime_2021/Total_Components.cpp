#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define mod 1000000007
#define debug(x) cout << #x << " " << x << endl;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n = 1e7;
    vector<char> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= n; i++)
    {
        if (is_prime[i] && (long long)i * i <= n)
        {
            for (ll j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    vector<ll> primeNums(n + 1);
    ll count = 0;
    for (ll i = 2; i <= n; i++)
    {
        if (is_prime[i])
            count++;
        primeNums[i] = count;
    }
    // debug(primeNums[n]);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        ll ans = 1;
        // int count = 0;
        // for (auto itr = primeNums.begin(); itr != primeNums.end() && (*itr <= n); itr++)
        // {
        //     int temp = *itr;
        //     debug(temp);
        //     if (temp > 500)
        //         count++;
        //     if (n / temp == 1)
        //     {
        //         ans++;
        //     }
        // }
        // cout << count << endl;
        if (n == 2)
            ans = 1;
        else if (n == 3)
            ans = 2;
        else
        {
            ans = (primeNums[n] - primeNums[n / 2]) + 1;
        }

        cout << ans << endl;
    }
}