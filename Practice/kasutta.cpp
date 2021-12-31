//Check out my youtube channel: https://www.youtube.com/c/QuarantineEngineers
//Join me on discord to discuss: https://discord.com/invite/6kcmVQx8Fx
#include<bits/stdc++.h>
using namespace std;
 
//common file for PBDS
#include<ext/pb_ds/assoc_container.hpp>
//including tree_order_statistics_node_update
#include<ext/pb_ds/tree_policy.hpp>
//namespace
using namespace __gnu_pbds;
#define int long long
 
//macro definition
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
 
#define ld long double
#define endl "\n"
const int mod=1000000007;
const int MAX=1000005;
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
 
const int bit=31;
//1.DP se soch
//2.DP se soch
//3.DP se soch
//graph, gcd, BS, seive
//if NOTA,then
//brute force hi optimal h
//jha confusion ho number of ways me vha dp dp dp 

int mul(int a, int b, int mod){
  return (a*b)%mod;
}
void solve(){
    int n,m;
    cin>>n>>m;
    int dp[n+1];
    dp[1]=1;
    int sum=1;
    for(int i=2;i<=n;i++){
      dp[i]=sum;
      for(int j=1;j*j<=i;j++){
        dp[i]=dp[i]+mul(dp[j],(i/j-i/(j+1)), m);
        dp[i]%=m;
        if(j!=i/j and j>1){
          dp[i]=dp[i]+dp[i/j];
          dp[i]%=m;
        }
      }
      sum=sum+dp[i];
      sum%=m;
      cout<<dp[i]<<endl;
    }
    cout<<dp[n];
    cout<<endl;
}

int32_t main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      // srand(time(0));
      int t;
      // cout<<fixed<<setprecision(10);
      t=1;
      // cin>>t;

      // for(auto x:v)cout<<x<<endl;
      // cin.ignore();
      // sieve(1000000);
      while(t--){
        // cout<<"Case #"<<tt<<": ";
            solve();
            // tt++;
      }
      return 0;
}