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
#define setPre(x) cout << fixed << showpoint; cout << setprecision(x);
#define pyn(flag) cout << (flag ? "YES" : "NO") << endl;
#define modc 1000000007
const long long inf=1e18;

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

const int N = 1005;
string grid[N];
int reachable[N][N][5];

bool valid(int x, int y, int n, int m) {
    if(x < 0 || y < 0) return 0;
    if(x >= n || y >= m) return 0;

    if(grid[x][y] == '*') return 0;

    return 1;
}

// directions : 1, 2, 3, 4
int bfs(int x, int y, int turns, int curr_direction, int n, int m) {
    // if(turns > 2) return 0;
    if(!valid(x, y, n, m)) return 0;

    if(grid[x][y] == 'S') return 0;

    if(grid[x][y] == 'T') {
        // debugg(curr_direction, turns);
        if(turns < 3) return 1;
        else return 0;
    }
    
    if(reachable[x][y][curr_direction] != -1) return reachable[x][y][curr_direction];


    bool ans = 0;
    if(curr_direction == 1) {
        if(reachable[x][y+1][1] == -1)
            ans |= reachable[x][y+1][1] = bfs(x, y+1, turns, curr_direction, n, m);
        if(reachable[x+1][y][1] == -1)
            ans |= reachable[x+1][y][1] = bfs(x+1, y, turns+1, 2, n, m);
        if(x > 0 && reachable[x-1][y][1] == -1)
            ans |= reachable[x-1][y][1] = bfs(x-1, y, turns+1, 4, n, m);
        
        // if(x == 0 && y == 4) {
        //     debug(reachable[x][y+1][1])
        //     debug(reachable[x+1][y][1]);
        //     debug(reachable[x-1][y][1]);
        // }
        
        // ans = (reachable[x][y+1][1] || reachable[x+1][y][1] || reachable[x-1][y][1]);
    } else if(curr_direction == 2) {
        //take left turn
        if(reachable[x][y+1][2] == -1)
            ans |= reachable[x][y+1][2] = bfs(x, y+1, turns+1, 1, n, m);
        //still going down
        if(reachable[x+1][y][2] == -1)
            ans |= reachable[x+1][y][2] = bfs(x+1, y, turns, 2, n, m);
        //take right turn
        if(y > 0 && reachable[x][y-1][2] == -1)
            ans |= reachable[x][y-1][2] = bfs(x, y-1, turns+1, 3, n, m);

        // ans = (reachable[x][y+1][2] || reachable[x+1][y][2] || reachable[x][y-1][2]);
    } else if(curr_direction == 3) {
        if(y > 0 && reachable[x][y-1][3] == -1)
            ans |= reachable[x][y-1][3] = bfs(x, y-1, turns, curr_direction, n, m);
        if(reachable[x+1][y][3] == -1)
            ans |= reachable[x+1][y][3] = bfs(x+1, y, turns+1, 2, n, m);
        if(x > 0 && reachable[x-1][y][3] == -1)
            ans |= reachable[x-1][y][3] = bfs(x-1, y, turns+1, 4, n, m);

        // ans =  (reachable[x][y-1][3] || reachable[x+1][y][3] || reachable[x-1][y][3]);
    } else {
        //take left turn
        if(reachable[x][y+1][4] == -1)
            ans |= reachable[x][y+1][4] = bfs(x, y+1, turns+1, 1, n, m);
        //still going down
        if(x > 0 && reachable[x-1][y][4] == -1)
            ans |= reachable[x-1][y][4] = bfs(x-1, y, turns, curr_direction, n, m);
        //take right turn
        if(y > 0 && reachable[x][y-1][4] == -1)
            ans |= reachable[x][y-1][4] = bfs(x, y-1, turns+1, 3, n, m);

        // ans = (reachable[x][y+1][4] || reachable[x-1][y][4] || reachable[x][y-1][4]);
    }
    
    // if(x == 0 && y == 4) {
    //     debugg(x, y);
    // debugg(curr_direction, turns);
    // debug(ans);
    // cout<<endl;
    // }
    
    
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    // cin>>tc;
    rep(test_case, 1, tc+1) {
        int n, m;
        cin>>n>>m;
        rep(i, 0, n) {
            cin>>grid[i];
        }

        mem1(reachable);
        // rep(i, 0, n) {
        //     rep(j, 0, m) {
        //         rep(k, 0, 5) {
        //             cout<<reachable[i][j][k]<<endl;
        //         }
        //     }
        // }

        bool ans, temp = 0;
        rep(i, 0, n) {
            rep(j, 0, m) {
                if(grid[i][j] == 'S') {
                    temp = 1;
                    int op1 = bfs(i, j+1, 0, 1, n, m);
                    int op2 = bfs(i+1, j, 0, 2, n, m);
                    int op3 = bfs(i, j-1, 0, 3, n, m);
                    int op4 = bfs(i-1, j, 0, 4, n, m);
                    
                    // debug(op1);
                    // debug(op2);
                    // debugg(op3, op4);

                    ans = (op1 || op2 || op3 || op4);
                    // ans = op3;
                    break;
                }
            }
            if(temp) break;
        }

        pyn(ans);
    }
}