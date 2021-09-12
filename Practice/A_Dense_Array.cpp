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
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int cnt = 0;
        for(int i=1; i<n; i++) {
            int big = max(arr[i], arr[i-1]);
            int small = min(arr[i], arr[i-1]);

            while(big > 2*small) {
                cnt++;
                small *= 2;
            }
        }

        cout<<cnt<<endl;


        
    }
}