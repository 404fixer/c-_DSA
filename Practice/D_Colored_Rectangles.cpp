/* Program By govindtomariiit */

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;
template<typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl "\n"
#define ll long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) (x).begin(),(x).end()
#define fr first
#define sc second
#define vi vector<int> 
#define mii map<int, int> 
#define mci map<char, int> 
#define pii pair<int,int>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define rep1(i, a, b) for(int i=a; i>=b; i--)
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define debug(x) cout<<#x<<" "<<x<<endl;
#define debugg(x, y) cout<<#x" "<<x<<" "<<#y<<" "<<y<<endl;

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
long long binpow(long long a, long long b) { long long res = 1; while (b > 0) { if (b & 1) res = res * a; a = a * a; b >>= 1; } return res;}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3:
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
void precision(int a) {cout << setprecision(a) << fixed;}
void pyn(bool flag) {cout << (flag ? "YES" : "NO") << endl;}
void pyn2(bool flag) {cout << (flag ? "Yes" : "No") << endl;}
/*--------------------------------------------------------------------------------------------------------------------------*/

#define int ll
const ll modc = 1000000007;
const ll inf = 1e18;
const int N = 205;

int ans[N][N][N];

ll solve(vi &rr, vi &gg, vi &bb, int ir, int ig, int ib) {
    if(ir < 0 || ig < 0 || ib < 0) {
        if((ir < 0 && ig < 0) || (ig < 0 && ib < 0) || (ir < 0 && ib < 0))
            return 0;
        
        if(ir < 0) {
            if(ans[0][ig+1][ib+1] != -1) return ans[0][ig+1][ib+1];

            return ans[0][ig+1][ib+1] = gg[ig]*bb[ib] + solve(rr, gg, bb, ir, ig-1, ib-1);
        } else if(ig < 0) {
            if(ans[ir+1][0][ib+1] != -1) return ans[ir+1][0][ib+1];

            return ans[ir+1][0][ib+1] = rr[ir]*bb[ib] + solve(rr, gg, bb, ir-1, ig, ib-1);
        } else if(ib < 0) {
            if(ans[ir+1][ig+1][0] != -1) return ans[ir+1][ig+1][0];

            return ans[ir+1][ig+1][0] = gg[ig]*rr[ir] + solve(rr, gg, bb, ir-1, ig-1, ib);
        } else {
            return -1;
        }
    }

    if(ans[ir+1][ig+1][ib+1] != -1) return ans[ir+1][ig+1][ib+1];

    int op1 = rr[ir]*gg[ig] + solve(rr, gg, bb, ir-1, ig-1, ib);
    int op2 = gg[ig]*bb[ib] + solve(rr, gg, bb, ir, ig-1, ib-1);
    int op3 = rr[ir]*bb[ib] + solve(rr, gg, bb, ir-1, ig, ib-1);
    return ans[ir+1][ig+1][ib+1] = max({op1, op2, op3});
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    // cin>>tc;
    rep(test_case, 1, tc+1) {
        int r, g, b;
        cin>>r>>g>>b;

        vi rr(r), gg(g), bb(b);
        rep(i, 0, r) cin>>rr[i];
        rep(i, 0, g) cin>>gg[i];
        rep(i, 0, b) cin>>bb[i];

        mem1(ans);

        sort(all(rr)); sort(all(gg)); sort(all(bb));
        ll ans = solve(rr, gg, bb, r-1, g-1, b-1);
        cout<<ans<<endl;
    }
}