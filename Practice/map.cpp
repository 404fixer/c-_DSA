#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
#define mod 1000000007
#define debug(x) cout<<#x<<" "<<x<<endl;
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);

   map<int, int> m;
   m.insert({2, 5});
   m.insert(make_pair(3, 7));
   for(auto itr : m) {
       cout<<itr.first<<" "<<itr.second<<endl;
   }

   for(auto itr = m.begin(); itr!= m.end(); itr++) {
       cout<<(*itr).first<<" "<<(*itr).second<<endl;
   }
}