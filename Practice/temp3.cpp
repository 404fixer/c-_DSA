#include<bits/stdc++.h>
using namespace std;


vector<long long> solve (int N, int M, vector<int> A, vector<vector<int> > Q) {
   // Write your code here
   vector<long long> res;
   for(long long i =0 ; i< M; i++) {
      vector<long long> b;
      long long cnt =0, sum = 0, l = 0;
      long long  k = Q[i][0];
      for(long long j = 0; j <= ((long long)N -k); j++) {
         if(cnt < k) {
            sum += A[i];
            cnt++;
            if(cnt == k) b.push_back(sum);
            
         } else {
            sum -= A[l];
            sum += A[i];
            b.push_back(sum);
            l++;
         }
      }

      sort(b.begin(), b.end());
      reverse(b.begin(), b.end());
      
      long long temp;
      bool f = 1;
      for(long long i = 0; i < Q[i][1]; i++) {
         if(f) {
            temp = b[i];
            f = 0;
            continue;
         }
           temp = temp & b[i];
      }
      long long z = temp | Q[i][2];
      res.push_back(z);
   }
   return res;

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int M;
    cin >> M;
    vector<int> A(N);
    for(int i_A = 0; i_A < N; i_A++)
    {
    	cin >> A[i_A];
    }
    vector<vector<int> > Q(M, vector<int>(3));
    for (int i_Q = 0; i_Q < M; i_Q++)
    {
    	for(int j_Q = 0; j_Q < 3; j_Q++)
    	{
    		cin >> Q[i_Q][j_Q];
    	}
    }

    vector<long long> out_;
    out_ = solve(N, M, A, Q);
    cout << out_[0];
    for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
    {
    	cout << " " << out_[i_out_];
    }
}