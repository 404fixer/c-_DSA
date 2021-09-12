/* Program By govindtomariiit */

#include<bits/stdc++.h>
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
#define setPre(x) cout << fixed << showpoint; cout << setprecision(x);
#define pyn(flag) cout << (flag ? "YES" : "NO") << endl;
#define modc 1000000007
const long long inf=1e18;
using namespace std;

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3:
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
void precision(int a) {cout << setprecision(a) << fixed;}
/*--------------------------------------------------------------------------------------------------------------------------*/

#define int ll
const int N = 51;
vi g[N];
vi c;
vi vis(N, 0);
multiset<int> res;

int dfs(int n) {
    vis[n] = 1;
    if(g[n].size() == 1) return c[n];

    ll maxi = LLONG_MIN;
    for(auto x: g[n]) {
        if(!vis[x]) {
            int te = dfs(x);
            if(maxi < (c[n] + te)) {
                if(maxi != LLONG_MIN)
                    res.insert(maxi-c[n]);
                maxi = c[n] + te;
            } else {
                res.insert(te);
            }
        }
    }
    // debugg(n, maxi);

    return  maxi;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    int govi = 1;
    cin>>t;
    while(t--) {
        int n, k;
        cin>>n>>k;

        rep(i, 0, n+1) {
            g[i].clear();
        }
        c.clear();
        vis = vi(n+1, 0);

        c.pb(0);
        rep(i, 1, n+1) {
            int x;
            cin>>x;
            c.pb(x);
        }

        rep(i, 0, n-1) {
            int l,r ;
            cin>>l>>r;
            g[l].pb(r);
            g[r].pb(l);
        }

        vis[1] = 1;
        int one = 0;
        res.clear();
        res.insert(-1);
        for(auto x: g[1]) {
            // debug(x);
            int te = dfs(x);
            // debug(te);
            res.insert(te);
            one++;
        }

        for(auto x: res) {
            cout<<x<<" ";
        } cout<<endl;


        auto itr = --res.end();
        ll ans = *itr;
        itr--;
        ans += c[1];
        int cnt = 0;
        // debug(res.size());
        while(itr != res.begin()) {
            // debug(*itr);
            ans += *itr;
            itr--;
            cnt++;

            // if(one > 1) {
                if(cnt == k) {
                    break;
                }
            // } else {
            //     if(cnt == (k-1)) {
            //         break;
            //     }
            // }
        }

        if(k==0) ans = c[1];

        google(govi);
        cout<<ans<<endl;
        govi++;
        cout<<endl;


    }
}