#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int check(int n,int m){
    bool a[n+1];
    memset(a,true,sizeof(a));
    for(int p=2; p*p<n;p++){
        if(a[p]==true){
            for(int i=p*2; i<=n; i+=p )
                a[i] = false;
        }
    }
    for(int i=2;i<=n;i++){
        if((a[i]==true) && (pow(i,m)==n))
            return 1;
    }
    return 0;
}
int main() {
    int t;
    long n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        int ans = check(n,m);
        if(ans == 1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
