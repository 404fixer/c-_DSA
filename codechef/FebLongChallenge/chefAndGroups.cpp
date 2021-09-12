#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;

    for(int idx= 0; idx<t; idx++) {
        string str;
        cin>>str;

        int count = 0;
        int numOfGps = 0;
        for(int i=0; i<str.length(); i++) {
            if(str[i] == '1') {
                count++;
                if(i== (str.length() - 1)) numOfGps++;
            } else if(str[i] == '0' && count !=0) {
                numOfGps++;
                count = 0;
            }
        }

        cout<<numOfGps<<endl;
    }

    return 0;
}