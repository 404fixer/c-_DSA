#include <iostream>
#include <cmath>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

//making a ordered set of pairs so that we can add duplicate items to the set
#define o_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int beautiful = 0;
        for (int i = 0; i < n; i++)
        {
            o_set subset;
            int freq[2001];
            for (int idx = 0; idx < 2001; idx++)
                freq[idx] = 0;
            for (int j = i; j < n; j++)
            {
                int length = j - i + 1;
                int m = ceil(((double)k) / length);
                int chotaX = ceil(((double)k) / m);
                chotaX--;
                subset.insert({arr[j], freq[arr[j]]++});
                auto itr = subset.find_by_order(chotaX);
                int X = (*itr).first;
                int frequency = freq[X];
                if (freq[frequency] > 0)
                    beautiful++;
            }
        }

        cout << beautiful << endl;
    }
}