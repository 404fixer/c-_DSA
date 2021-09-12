#include <bits/stdc++.h>
using namespace std;

int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int idx = 0; idx < t; idx++)
    {
        int n;
        cin >> n;

        int maxSpeed[n];
        for (int i = 0; i < n; i++)
        {
            cin >> maxSpeed[i];
        }

        int numOfMaxSpeedCars = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (maxSpeed[i] > maxSpeed[i + 1])
                numOfMaxSpeedCars++;
            else
                maxSpeed[i + 1] = maxSpeed[i];
        }

        cout << numOfMaxSpeedCars << "\n";
    }
}