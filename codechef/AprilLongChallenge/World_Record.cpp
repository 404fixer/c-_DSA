#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        float k1, k2, k3, v;
        cin >> k1 >> k2 >> k3 >> v;

        float speed = k1 * k2 * k3 * v;
        float time = 100 / speed;
        int temp = (int)(time * 100 + .5);
        float accTime = (float)temp / 100;
        if (accTime < (float)9.58)
            cout << "yes" << endl;
        else
            cout << "No" << endl;
    }
}