#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#define endl "\n"
#define ll long long
#define MOD 1000000007
#define debug(x) cout << #x << " " << x << endl;
using namespace std;

int n, m;
vector<int> temp_prime;

bool isPrime(int x, int y)
{

    for (int i = 2; i <= n && i <= x; i++)
    {
        if (temp_prime[i] == 0)
        {
            if (x % i == 0 && y % i == 0)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    vector<pair<char, int>> op(m);
    for (int i = 0; i < m; i++)
    {
        cin >> op[i].first >> op[i].second;
    }

    // for (int i = 0; i < m; i++)
    // {
    //     cout << op[i].first << " " << op[i].second << endl;
    // }

    for (int i = 0; i <= n; i++)
    {
        temp_prime.push_back(0);
    }

    for (ll i = 2; i <= n; i++)
    {
        if (temp_prime[i] == 0)
        {
            for (ll j = i * i; j <= n; j += i)
            {
                temp_prime[j] = 1;
            }
        }
    }

    set<int> s;
    s.clear();
    for (int i = 0; i < m; i++)
    {
        // cout << op[i].first << endl;
        if (op[i].first == '+')
        {
            if (s.empty())
            {
                s.insert(op[i].second);
                cout << "Success" << endl;
            }
            else if (*(s.lower_bound(op[i].second)) == op[i].second)
            {
                cout << "Already on" << endl;
            }
            else
            {
                bool temp = true;
                for (auto itr : s)
                {
                    if (isPrime(itr, op[i].second))
                    {
                        cout << "Conflict with " << itr << endl;
                        temp = false;
                        break;
                    }
                }
                if (temp)
                {
                    s.insert(op[i].second);
                    cout << "Success" << endl;
                }
            }
        }
        else
        {
            if (*(s.lower_bound(op[i].second)) == op[i].second)
            {
                s.erase(op[i].second);
                cout << "Success" << endl;
            }
            else
            {
                cout << "Already off" << endl;
            }
        }
    }
}