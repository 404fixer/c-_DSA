#include <iostream>
using namespace std;

int getBit(int n, int position)
{
    if ((n & (1 << position)) != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int setBit(int n, int index)
{
    return (n | (1 << index));
}

int clearBit(int n, int index)
{
    int mask = ~(1 << index); //this is called masking
    return (n & mask);
}

int updateBit(int n, int index, int digit)
{
    //clear the bit
    int clearedBit = clearBit(n, index);
    //then set the bit
    return (n | (digit << index));
}

int main()
{
    int n, position;
    int digit;
    cin >> n >> position >> digit;

    cout << getBit(n, position) << endl;

    cout << setBit(n, position) << endl;

    cout << clearBit(n, position) << endl;

    cout << updateBit(n, position, digit) << endl;
}