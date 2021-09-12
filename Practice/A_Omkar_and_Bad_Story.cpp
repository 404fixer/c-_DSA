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
        int n;
        cin >> n;
        int arr[n];
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        sort(v.begin(), v.end());
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            for (int j = i;; j < n; j++)
            {
                if (binary_search(v.begin(), v.end(), abs(arr[i] - arr[j])))
                    continue;
                else
                {
                    s.insert(abs(arr[i] - arr[j]));
                }
            }
        }
        for (auto itr : s)
        {
            for (int i = 0; i < v.size(); i++)
            {
                if (binary_search(v.begin(), v.end(), abs(arr[i] - itr)))
                    continue;
                else
                {
                    s.insert(abs(arr[i] - itr));
                }
                v.push_back(itr);
            }
        }
        if (v.size > 300)
            cout << "NO" << endl;
        else
        {
        }
    }
}