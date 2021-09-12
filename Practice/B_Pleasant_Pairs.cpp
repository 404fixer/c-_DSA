#include <bits/stdc++.h>
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<lli, lli>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;

int ar[200001];
ii br[200001];

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        REP(i, n) cin >> ar[i], br[i] = {ar[i], i};

        sort(br + 1, br + n + 1);

        lli res = 0;
        for (int i = 1; i <= n; i++) {
            for (lli j = i + 1; j <= n; j++) {
                lli L = br[i].ss + br[j].ss;
                lli R = br[i].ff * br[j].ff;

                if (L == R) res++;

                if (R > 2 * n) break;
            }
        }

        cout << res << endl;
    }
}
