/* Program By govindtomariiit */

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;
template<typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define int ll
// #define endl "\n" //comment in interactive problems
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
string to_string(char c) {return string(1, c);}
void precision(int a) {cout << setprecision(a) << fixed;}
void pyn(bool flag) {cout << (flag ? "YES" : "NO") << endl;}
void pyn2(bool flag) {cout << (flag ? "Yes" : "No") << endl;}
/*--------------------------------------------------------------------------------------------------------------------------*/

const ll modc = 1000000007;
const ll inf = 1e18;
const int N = (1*(1e5)) + 5;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin>>tc;
    rep(test_case, 1, tc+1) {
        int n;
        cin>>n;

        int a = 1, b = 2;
        set<int> s;
        int cnt = 3;
        rep(i, 0, ((2*n)/3) - 1) {
            cout<<"? "<<a<<" "<<b<<" "<<cnt<<endl;

            int x; cin>>x;
            s.insert(x);
            cnt++;
        }

        set<int> res;
        if(s.size() == 2) {
            cnt = 3;

            int crew;
            rep(i, 0, n-2) {
                cout<<"? "<<a<<" "<<b<<" "<<cnt<<endl;
                int x; cin>>x;

                if(x == 0) res.insert(cnt);
                else crew = cnt;
                cnt++;
            }

            cout<<"? "<<a<<" "<<crew<<" "<<*res.begin()<<endl;
            int x; cin>>x;
            if(x == 0) res.insert(a);
            else res.insert(b);
        } else {
            int idx = 1;
            if(*s.begin() == 0) {
                for(int i = 4; i < n; i += 3) {
                    cout<<"? "<<i<<" "<<i+1<<" "<<i+2<<endl;
                    int x; cin>>x;
                    if(x == 1) {
                        idx = i;
                        break;
                    }
                }

                vector<pii> options = {{idx, idx+1}, {idx+1, idx+2}, {idx, idx+2}};
                int crew, crew2;
                rep(i, 0, 3) {
                    cout<<"? "<<a<<" "<<options[i].fr<<" "<<options[i].sc<<endl;
                    int x; cin>>x;
                    if(x == 1) {
                        crew = options[i].fr;
                        crew2 = options[i].sc;
                        break;
                    }
                }
                res.insert(a); res.insert(b);
                rep(i, 3, n+1) {
                    if(i == crew || i == crew2) continue;
                    cout<<"? "<<a<<" "<<crew<<" "<<i<<endl;
                    int x; cin>>x;
                    if(x == 0) res.insert(i);
                }
            } else {
                for(int i = 4; i < n; i += 3) {
                    cout<<"? "<<i<<" "<<i+1<<" "<<i+2<<endl;
                    int x; cin>>x;
                    if(x == 0) {
                        idx = i;
                        break;
                    }
                }

                vector<pii> options = {{idx, idx+1}, {idx+1, idx+2}, {idx, idx+2}};
                int imposter, imposter2;
                rep(i, 0, 3) {
                    cout<<"? "<<a<<" "<<options[i].fr<<" "<<options[i].sc<<endl;
                    int x; cin>>x;
                    if(x == 0) {
                        imposter = options[i].fr;
                        imposter2 = options[i].sc;
                        break;
                    }
                }
                res.insert(imposter); res.insert(imposter2);
                rep(i, 3, n+1) {
                    if(i == imposter || i == imposter2) continue;
                    cout<<"? "<<a<<" "<<imposter<<" "<<i<<endl;
                    int x; cin>>x;
                    if(x == 0) res.insert(i);
                }
            }
        }

        cout<<"! "<<res.size()<<" ";
        for(auto x: res) cout<<x<<" ";
        cout<<endl;
    }
}