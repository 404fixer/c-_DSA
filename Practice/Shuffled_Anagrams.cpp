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

const int N = 1e5 + 1;

set<string> ans2;

void permute(string a, int l, int r)
{
    // Base case
    if (l == r)
        ans2.insert(a);
        // cout<<a<<endl;
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {
 
            // Swapping done
            swap(a[l], a[i]);
 
            // Recursion called
            permute(a, l+1, r);
 
            //backtrack
            swap(a[l], a[i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    int cnt = 1;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;

        string ans;

        int lol = -1;
        if(s.size() <= 8) {
            ans2.clear();
            permute(s, 0, s.size()-1);
            for(auto x: ans2) {
                lol = 0;
                rep(i, 0, s.size()) {
                    if(s[i] != x[i]) lol++;
                    else break;
                }
                if(lol == s.size()) {
                    google(cnt);
                    cout<<x<<endl;
                    break;
                }
            }

            if(lol != s.size()) {
                    google(cnt);
            cout<<"IMPOSSIBLE\n";

            }
            cnt++;
            continue;
        }

        int l = 0, r = s.size()-1;
        stack<int> st;
        ans = s;
        while(l < r) {
            if(s[l] != s[r]) {
                if(st.empty()) {
                    swap(ans[l], ans[r]);
                } else if(!st.empty()) {
                    if(s[st.top()] != s[l] && s[st.top()] != s[r]) {
                        swap(ans[st.top()], ans[l]);
                        st.pop();
                        swap(ans[st.top()], ans[r]);
                        st.pop();
                    } else {
                        swap(ans[l], ans[r]);
                    }
                }
                l++, r--;
            } else {
                if(st.empty()) {
                    st.push(l);
                    st.push(r);
                } else {
                    if(s[st.top()] != s[l]) {
                        swap(ans[st.top()], ans[l]);
                        st.pop();
                        swap(ans[st.top()], ans[r]);
                        st.pop();
                    } else {
                        st.push(l);
                        st.push(r);
                    }
                }
                l++, r--;
            }
        }

        bool fine = false;
        if(s.size()%2 == 1) {
            int idx = s.size()/2;
            int up = s.size()/2;
            rep(i, 0, up) {
                if(s[idx] != s[i] && s[idx] != s[s.size()-i-1]) {
                    fine = true;
                    swap(ans[idx], ans[i]);
                    break;
                }
            }
        } else {
            fine = true;
        }


        if(s.size()%2 == 1 && !fine) {
            google(cnt);
            cout<<"IMPOSSIBLE\n";
        } else if(st.empty() && fine) {
            google(cnt);
            cout<<ans<<endl;
        } else {
            if(s.size()%2 == 1) {
                l = s.size()/2;
                l--;
                r = s.size()/2;
                r++;
            } else {
                l = s.size()/2;
                l--;
                r = s.size()/2;
            }

            while(!st.empty()) {
                st.pop();
            }
            ans = s;
            while(l>= 0 && r<s.size()) {
                if(s[l] != s[r]) {
                    if(st.empty()) {
                        swap(ans[l], ans[r]);
                    } else if(!st.empty()) {
                        if(s[st.top()] != s[l] && s[st.top()] != s[r]) {
                            swap(ans[st.top()], ans[l]);
                            st.pop();
                            swap(ans[st.top()], ans[r]);
                            st.pop();
                        } else {
                            swap(ans[l], ans[r]);
                        }
                    }
                } else {
                    if(st.empty()) {
                        st.push(l);
                        st.push(r);
                    } else {
                        if(s[st.top()] != s[l]) {
                            swap(ans[st.top()], ans[l]);
                            st.pop();
                            swap(ans[st.top()], ans[r]);
                            st.pop();
                        } else {
                            st.push(l);
                            st.push(r);
                        }
                    }
                }
                l--, r++;
            }

            if(s.size()%2 == 1) {
                int idx = s.size()/2;
                int up = s.size()/2;
                rep(i, 0, up) {
                    if(s[idx] != s[i] && s[idx] != s[s.size()-i-1]) {
                        swap(ans[idx], ans[i]);
                        break;
                    }
                }
            }

            if(st.empty()) {
                google(cnt);
                cout<<ans<<endl;
            } else {
                google(cnt);
                cout<<"IMPOSSIBLE\n";
            }
        }


        cnt++;
    }
}