#include <iostream>
#include <set>
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    multiset<pair<long long, long long>> deadlines;
    for (int i = 0; i < n; i++)
    {
        long long x, y;
        cin >> x >> y;
        deadlines.insert(make_pair(x, y));
    }

    long long time = 0;
    long long ans = 0;
    for (auto const &element : deadlines)
    {
        time += element.first;
        ans += (element.second - time);
    }

    cout << ans << endl;
}