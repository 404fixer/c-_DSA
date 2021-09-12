#include <iostream>
using namespace std;

int main()
{
    float n;
    cin >> n;

    int intPart = (int)n;
    float decimalPart = n - (float)(int)n;

    cout << intPart << endl;
    cout << decimalPart << endl;
}