#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll minInsert(string s, ll n){
    ll t[n][n],l,h,g;

    memset(t,0,sizeof(t));

    for(g=1;g<n;g++){
        for(l=0,h=g;h<n;l++,h++){
            t[l][h] = (s[l]==s[h])? t[l+1][h-1] : (min(t[l][h-1],t[l+1][h])+1);
        }
    }
    return t[0][n-1];
}

int main(){
    ll n;
    cin>>n;
    string s;
    cin>>s;

    cout<<minInsert(s,n)<<endl;
}
