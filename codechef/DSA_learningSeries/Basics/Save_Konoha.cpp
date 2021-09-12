#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, z;
        cin >> n >> z;

        priority_queue<int> powers;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            powers.push(x);
        }

        long int shots = 0;
        while (z > 0 && powers.top() > 0)
        {
            z -= powers.top();
            shots++;
            if (powers.top() != 1)
                powers.push(powers.top() / 2);
            powers.pop();
        }

        z <= 0 ? cout << shots << endl : cout << "Evacuate\n";
    }
}