#include <iostream>
#include <set>
#include <string>
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string mstr;
    cin >> mstr;
    int n;
    cin >> n;
    set<string> words;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        words.insert(str);
    }

    for (auto element : words)
    {
    }
}