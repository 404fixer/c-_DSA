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
#define modc 1000000007
const long long inf=1e18;

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
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
/*--------------------------------------------------------------------------------------------------------------------------*/

const int N = (1*(1e5)) + 5;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    // cin>>tc;
    rep(test_case, 1, tc+1) {
        int n;
        cin>>n;
        int a[n], b[n];
        mii cnt;
        rep(i, 0, n) {
            cin>>a[i];
            cnt[a[i]]++;
            b[i] = a[i];
        }

        int ans = n;
        if(cnt.size() == 3) {
            auto itr = cnt.begin();
            auto itr2 = --cnt.end();
            auto itr3 = itr;
            itr3++;
            int temp = min(itr->sc, itr2->sc);

            int temp2 = temp;
            ans = n - temp - temp2;
            rep(i, 0, n) {
                if(temp && a[i] == itr->fr) {
                    a[i] = itr3->fr;
                    temp--;
                }

                if(temp2 && a[i] == itr2->fr) {
                    a[i] = itr3->fr;
                    temp2--;
                }

                if(temp == 0 &&temp2 == 0) break;
            }

            temp = itr3->sc/2;
            temp2 = temp;
            int ans2 = n - temp - temp2;
            rep(i, 0, n) {
                if(temp && b[i] == itr3->fr) {
                    b[i] = b[i] + 1;
                    temp--;
                }
                if(!temp && temp2 && b[i] == itr3->fr) {
                    b[i] = b[i] - 1;
                    temp2--;
                }

                if(temp == 0 && temp2 == 0) break;
            }

            if(ans2 < ans) {
                ans = ans2;
                rep(i, 0, n) {
                    a[i] = b[i];
                }
            }
        } else if(cnt.size() == 2) {
            auto itr = cnt.begin();
            auto itr2 = --cnt.end();

            if(itr2->fr - itr->fr < 2) goto here;

            int temp = min(itr->sc, itr2->sc);
            int temp2 = temp;
            ans = n - temp - temp2;
            rep(i, 0, n) {
                if(temp && a[i] == itr->fr) {
                    a[i]++;
                    temp--;
                }

                if(temp2 && a[i] == itr2->fr) {
                    a[i]--;
                    temp2--;
                }

                if(temp == 0 &&temp2 == 0) break;
            }
        }

        here:
        cout<<ans<<endl;
        rep(i, 0, n) {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}