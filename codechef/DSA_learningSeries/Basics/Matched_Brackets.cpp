#include <bits/stdc++.h>
#include <utility>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int countBrackets = 0;
    int depth = 0;
    int depthIndex = -1;
    pair<int, int> symbols(-1, 0);
    pair<int, int> indexAndLen(-1, 0);

    for (int i = 0; i < n; i++)
    {
        symbols.second++;

        if (arr[i] == 1)
        {
            countBrackets++;
            if (countBrackets == 1 && symbols.first == -1)
            {
                symbols.first = i;
            }
        }
        else
        {
            if (countBrackets > depth)
            {
                depth = countBrackets;
                depthIndex = i;
            }
            countBrackets--;
            if (countBrackets == 0)
            {
                if (indexAndLen.second < symbols.second)
                {
                    // cout << i << endl;
                    // cout << symbols.second << endl;
                    // cout << indexAndLen.second << endl;
                    indexAndLen.second = symbols.second;
                    indexAndLen.first = symbols.first;
                }
                symbols = make_pair(-1, 0);
            }
        }
    }

    cout << depth << " " << depthIndex << " " << indexAndLen.second << " " << indexAndLen.first + 1 << endl;
}