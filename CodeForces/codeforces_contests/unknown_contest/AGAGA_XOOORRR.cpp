#include <iostream>
#define endl "\n"
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
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int xor_of_arr = arr[0];
        for (int i = 1; i < n; i++)
        {
            xor_of_arr = arr[i] ^ xor_of_arr;
        }

        if (xor_of_arr == 0)
            cout << "YES" << endl;
        else
        {
            int idx1 = 0, idx2 = n - 1;
            int p = 0, q = 0;
            while (idx1 < n && p != xor_of_arr)
            {
                p ^= arr[idx1];
                if (p == xor_of_arr)
                    break;
                idx1++;
            }
            while (idx2 >= 0 && q != xor_of_arr)
            {
                q ^= arr[idx2];
                if (q == xor_of_arr)
                    break;
                idx2--;
            }

            if (idx1 < idx2 - 1)
            {
                cout << "YES" << endl;
            }
            else
                cout << "NO" << endl;
        }
    }
}