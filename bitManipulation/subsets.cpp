#include <bits/stdc++.h>
using namespace std;

void subsets(int arr[], int n)
{
    for (int i = 0; (i < (1 << n)); i++)
    {
        //traversing through the bits of i and taking one bit at a time of i
        for (int j = 0; j < n; j++)
        {
            //applied getBit()
            if (i & (1 << j))
            {
                //remember it is printing the jth element for maintaining the order of subarrays
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{

    int arr[] = {1, 2, 3};
    subsets(arr, 3);
}