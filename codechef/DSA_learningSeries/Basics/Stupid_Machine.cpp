#include <bits/stdc++.h>
#include <utility>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int idx = 0; idx < t; idx++)
    {
        int n;
        cin >> n;

        long int capacity[n];
        for (int i = 0; i < n; i++)
        {
            cin >> capacity[i];
        }

        long int tokens = 0;
        long int minCapacity = INT_MAX;
        pair<int, long int> index[n];
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (capacity[i] < minCapacity)
            {
                index[count] = make_pair(i, capacity[i]);
                minCapacity = capacity[i];
                count++;
            }
        }

        int numOfBoxes = n;
        long int individual_filled = 0;
        for (int i = count - 1; i >= 0; i--)
        {
            tokens += ((index[i].second - individual_filled) * numOfBoxes);
            individual_filled = index[i].second;
            numOfBoxes = index[i].first;
        }

        cout << tokens << endl;
    }
}