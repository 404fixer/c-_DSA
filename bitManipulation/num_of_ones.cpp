#include <bits/stdc++.h>
using namespace std;

int numOfOnes(int n)
{
    int temp = 0;
    while ((n & (n - 1)) != 0)
    {
        temp++;
        n = (n & (n - 1));
    }

    return (temp + 1);
}

int main()
{
    int n;
    cin >> n;

    cout << numOfOnes(n) << endl;
}