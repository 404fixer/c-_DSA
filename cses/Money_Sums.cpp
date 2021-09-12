#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <cmath>
#include <string.h>
#include <algorithm>
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

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    set<ll> sums;
    for (int i = 0; i < n; i++)
    {
        if (!sums.empty())
        {
            set<ll> curr;
            for (auto x : sums)
                curr.insert(x + (ll)arr[i]);
            for (auto x : curr)
                sums.insert(x);
        }
        sums.insert(arr[i]);
    }

    cout << sums.size() << endl;
    for (auto x : sums)
        cout << x << " ";
    cout << endl;
}