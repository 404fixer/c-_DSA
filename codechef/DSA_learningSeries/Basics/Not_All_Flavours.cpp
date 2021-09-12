#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int idx = 0; idx < t; idx++)
    {
        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int distinctFlavour = 1;
        int l = 0, r = 0;
        int flavf[k + 1];
        for (int i = 0; i <= k; i++)
            flavf[i] = 0;

        flavf[arr[0]] = 1;
        int maxRange = 1;

        while (true)
        {
            while (++r < n && distinctFlavour < k)
            {
                if (flavf[arr[r]] == 0)
                    distinctFlavour++;
                flavf[arr[r]]++;
                if (distinctFlavour < k)
                    maxRange = max(maxRange, r - l + 1);
            }
            if (r == n)
                break;
            r--;
            while (l <= r && distinctFlavour == k)
            {
                if (flavf[arr[l]] == 1)
                    distinctFlavour--;
                flavf[arr[l]]--;
                l++;
            }
        }
        cout << maxRange << endl;
    }
}