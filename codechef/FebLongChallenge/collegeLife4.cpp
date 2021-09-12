#include<bits/stdc++.h>
using namespace std;

int MaxNumOfItems(int e, int h) {
    if(e== h) {
        return e;
    } else if(e < h) {
        return (e + ((h-e)/3));
    } else {
        return (h + ((e-h)/2));
    }
}

int NumOfOmelette(int e) {
    return (e/2);
}

int NumOfMilkshake(int h) {
    return (h/3);
}

int NumOfCake(int e, int h) {
    return (e>=h ? h : e);
}

int minCost(int n, int e, int h, int a, int b, int c) {
    if(a<b && a<c) {
        int minCostItems = n*2;
        if(minCostItems >= e) {
            return a*n;
        } else {

        }
    }
}

int main() {
    int t;
    cin>>t;

    for(int idx=0; idx<t; idx++) {
        int n,e,h,a,b,c;
        cin>>n>>e>>h>>a>>b>>c;

        int maxItems = 0;
        maxItems = MaxNumOfItems(e, h);

        int cost = 0;
        if(maxItems >= n) {

        } else {
            cout<<"-1\n";
        }
        
    }
}
