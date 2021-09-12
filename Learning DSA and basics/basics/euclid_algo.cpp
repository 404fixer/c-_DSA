#include <iostream>
using namespace std;

int getGCD(int m, int n)
{

    while (n != 0)
    {
        int temp = n;
        n = m % n;
        m = temp;
    }

    return m;
}

int main()
{
    int m, n;
    cin >> m >> n;

    cout << getGCD(m, n) << endl;
}