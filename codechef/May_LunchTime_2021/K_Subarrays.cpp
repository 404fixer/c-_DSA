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

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll arr[n];
        for (ll i = (ll)0; i < n; i++)
            cin >> arr[i];

        ll maxScore = LLONG_MIN;
        ll temp = (ll)0;
        for (ll i = (ll)0; i < n && k == (ll)1; i++)
        {
            if (arr[i] >= (ll)0)
            {
                temp += arr[i];
                maxScore = max(maxScore, temp);
            }
            else
            {
                maxScore = max(maxScore, arr[i]);
                temp = (ll)0;
            }
        }

        cout << maxScore << endl;
    }
}