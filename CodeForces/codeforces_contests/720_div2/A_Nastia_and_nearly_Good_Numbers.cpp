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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        cout << "YES" << endl;
        if (n == 1 && m == 1)
        {
            cout << 6 << " " << 3 << " " << 9 << endl;
        }
        else if (m == 1)
        {
            cout << n << " " << n * 2 << " " << n * 3;
        }
        else
        {
            // if (n % m != 0)
            // if (m != 2)
            //     cout << n * (m - 1) << " " << n * 1 << " " << m * n << endl;
            // else
            //     cout << n * ((2 * m) - 1) << " " << n * 1 << " " << 2 * m * n << endl;

            for (ll i = 1; true; i++)
            {
                ll x = n * ((i * m) - 1);
                ll y = n * 1;
                ll z = i * m * n;

                if (x != y && x + y == z)
                {
                    cout << x << " " << y << " " << z << endl;
                    break;
                }
                else
                {
                    x = n * ((i * m) + 1);
                    y = n * 1;
                    z = i * m * n;

                    if (x != y && ((x - y) == z))
                    {
                        cout << x << " " << y << " " << z << endl;
                        break;
                    }
                }
            }
        }
    }
}

SELECT name FROM movieStar, movie WHERE title = movieTitle AND year = movieYear AND year = 1995 AND studioName = 'MGM Studios';
SELECT M1.title FROM movie AS M1, Movie AS M2 WHERE M2.title = 'Gone With the Wind' AND M1.length > M2.length;
SELECT M1.name FROM movieExec AS M1, MovieExec AS M2 WHERE M2.name = 'Mery Griffin' AND M1.networth > M2.networth;