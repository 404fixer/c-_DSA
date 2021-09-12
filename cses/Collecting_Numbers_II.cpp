#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    int mid = l + ((r - l) / 2);

    if (arr[mid] == x)
        return mid;
    else if (arr[mid] < x)
        binarySearch(arr, mid + 1, r, x);
    else
        binarySearch(arr, l, mid - 1, x);

    return -1;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<pair<int, int>> swaps(m);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        swaps[i].first = x;
        swaps[i].second = y;
    }

    int nums[n + 1], ans = 0;
    for (int i = 0; i < n + 1; i++)
        nums[i] = 0;
    for (int i = 0; i < n; i++)
    {
        nums[arr[i]]++;

        if (nums[arr[i] - 1] == 0)
        {
            ans++;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int l = swaps[i].first - 1;
        int r = swaps[i].second - 1;

        //swap the nums
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;

        //checking if l affect ans
        
    }
}