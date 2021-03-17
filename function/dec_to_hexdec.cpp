#include <bits/stdc++.h>
using namespace std;

string dec_to_hexdec(int n)
{
    int x = 16;
    string dec = "", temp_str;
    while (n > 0)
    {
        int rem = n % x;
        n /= x;
        if (rem <= 9)
        {
            temp_str = to_string(rem);
        }
        else
        {
            rem += 55;
            char c = rem;
            std::string s(1, c);
            temp_str = s;
        }
        dec.insert(0, temp_str);
    }
    return dec;
}

int main()
{
    int n;
    cin >> n;

    cout << dec_to_hexdec(n) << endl;
}