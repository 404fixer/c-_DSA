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
        int positives = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] >= 0)
                positives++;
        }

        sort(arr, arr + n);
        // for (int i = 0; i < n; i++)
        //     cout << arr[i] << " ";
        // cout << endl;
        int l = 0, r = n - 1;
        ll ans = 1;
        if (positives == 0)
        {
            for (int i = n - 1; i >= n - 5; i--)
                ans *= arr[i];
        }
        else if (positives <= 2)
        {
            for (int i = 0; i < 4; i++)
                ans *= arr[i];
            ans *= arr[n - 1];
        }
        else
        {
            ans *= arr[r];
            r--;
            positives--;
            for (int i = 0; i < 2; i++)
            {
                // debug(i);
                ll op1 = (ll)(arr[l] * arr[l + 1]);
                ll op2 = (ll)(arr[r] * arr[r - 1]);
                // debug(op1);
                // debug(op2);

                if (op1 > op2)
                {
                    ans *= op1;
                    l += 2;
                }
                else if (op1 < op2)
                {
                    ans *= op2;
                    r -= 2;
                }
                else
                {
                    if (i == 0)
                        ans *= (op1 * op2);
                    if (i == 1)
                        ans *= op1;
                    l += 2;
                    r -= 2;
                    break;
                }
                // debug(l);
                // debug(r);
                // debug(ans);
            }
        }

        cout << ans << endl;
    }
}