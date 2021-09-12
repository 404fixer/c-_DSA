#include <iostream>
#define endl "\n"
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

    int len1 = 0, len2 = 0, ans = 0;
    int last = arr[0], curr = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != curr)
        {
            last = curr;
            len1 = len2;
            curr = arr[i];
            len2 = 1;
        }
        else
        {
            len2++;
        }
        ans = max(ans, min(len1, len2));
    }

    cout << ans * 2 << endl;
}