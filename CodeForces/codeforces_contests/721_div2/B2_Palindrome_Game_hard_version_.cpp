#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <cmath>
#include <string>
#include <algorithm>
#define endl "\n"
#define ll long long
#define mod 1000000007
#define debug(x) cout << #x << " " << x << endl;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string str;
        cin >> str;

        int nonPdmZeros = 0, pdmZeros = 0;
        for (int i = 0; i < (n / 2); i++)
        {
            if (str[i] != str[(n - 1 - i)])
                nonPdmZeros++;
            if (str[i] == '0' && str[i] == str[(n - 1 - i)])
                pdmZeros += 2;
        }
        if (((n % 2) == 1) && (str[n / 2] == '0'))
            pdmZeros++;
        // debug(nonPdmZeros);
        // debug(pdmZeros);

        int alice = 0, bob = 0;
        // bool isAlice = true;
        if (nonPdmZeros == 1)
        {
            if (pdmZeros == 0)
                bob = 1;
            else
            {
                alice++;
            }
        }
        else if (nonPdmZeros != 0)
        {
            if (pdmZeros == 0)
            {
                bob = nonPdmZeros;
            }
            else
            {
                bob = nonPdmZeros - 1;
                alice++;
            }

            //alice 0101
            //bob 1101      a0 b1
            //alice 1011 a0 b1
        }
        // debug(alice);
        // debug(bob);
        // debug(pdmZeros);

        // if nonpdmzeros = 0 then, alice will start
        // if nonPdmZeros != 0, then, bob will play first;
        if (pdmZeros != 0)
        {
            if (nonPdmZeros != 0)
            {
                if (pdmZeros % 2 == 1)
                {
                    if (pdmZeros == 1)
                    {
                        bob++;
                    }
                    else
                    {
                        bob++;
                        pdmZeros--;
                        alice += (pdmZeros / 2) + 1;
                        bob += (pdmZeros / 2) - 1;
                    }
                }
                else
                {
                    bob += (pdmZeros / 2) + 1;
                    alice += (pdmZeros / 2) - 1;
                }
            }
            else
            {
                if (pdmZeros % 2 == 1)
                {
                    if (pdmZeros == 1)
                    {
                        alice++;
                    }
                    else
                    {
                        alice++;
                        pdmZeros--;
                        bob += (pdmZeros / 2) + 1;
                        alice += (pdmZeros / 2) - 1;
                    }
                }
                else
                {
                    alice += (pdmZeros / 2) + 1;
                    bob += (pdmZeros / 2) - 1;
                }
            }
        }
        // debug(alice);
        // debug(bob);

        if (alice < bob)
            cout << "ALICE" << endl;
        else if (alice > bob)
            cout << "BOB" << endl;
        else
            cout << "DRAW" << endl;

        // cout << "================" << endl;
    }
}