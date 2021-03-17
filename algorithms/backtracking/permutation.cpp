#include <bits/stdc++.h>
using namespace std;

string str;

void permutation(string str, int idx, int n)
{
    if (idx == n)
    {
        cout << str << endl;
    }
    else
    {
        for (int i = idx; i <= n; i++)
        {
            // swaping done
            swap(str[idx], str[i]);

            // Recursion called
            permutation(str, idx + 1, n);

            //Backtracking
            swap(str[idx], str[i]);
        }
    }
}

int main()
{
    cin >> str;
    int n = str.size();

    permutation(str, 0, n - 1);
}