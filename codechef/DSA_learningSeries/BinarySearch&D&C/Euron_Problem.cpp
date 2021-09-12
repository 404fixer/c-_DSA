#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#define endl "\n"
#define ll long long
#define MOD 1000000007
using namespace std;

ll temp_count = 0;

void merge(int arr[], int l, int mid, int r)
{
    int lidx1 = l, lidx2 = mid + 1;
    int arr2[r];
    int i = l;
    while (lidx1 <= mid && lidx2 <= r)
    {
        if (arr[lidx1] > arr[lidx2])
        {
            temp_count += (long long)(mid - lidx1 + 1);
            // cout << "temp " << temp_count << " " << arr[lidx1] << " " << arr[lidx2] << endl;
            arr2[i] = arr[lidx2];
            i++;
            lidx2++;
        }
        else
        {
            arr2[i] = arr[lidx1];
            i++;
            lidx1++;
        }
        // cout << "arr " << arr2[i] << endl;
    }

    while (lidx1 <= mid)
    {
        arr2[i] = arr[lidx1];
        lidx1++;
        i++;
    }

    while (lidx2 <= r)
    {
        arr2[i] = arr[lidx2];
        lidx2++;
        i++;
    }

    while (l <= r)
    {
        arr[l] = arr2[l];
        l++;
    }
}

void mergeSort(int arr[], int l, int r)
{

    if (l < r)
    {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
    return;
}

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

    mergeSort(arr, 0, n - 1);
    cout << temp_count << endl;
}