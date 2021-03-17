#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, h, x;
    cin>>n>>h>>x;

    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    bool haveTime = false;
    for(int i=0; i<n; i++) {
        if((arr[i] + x) >= h) {
            haveTime = true;
            break;
        }
    }

    haveTime ? cout<<"YES"<<endl : cout<<"NO"<<endl;
}