#include<iostream>
using namespace std;

int main() {
    int n, k;
    cin>>n>>k;
    
    int remainingTime = 240 - k;
    int count = 0;
    for(int i=1; i<=n; i++) {
        int problemSolvingTime = ((i*(i+1))/2)*5;
        if(problemSolvingTime <= remainingTime) count++;
        else break;
    }

    cout<<count<<endl;

}