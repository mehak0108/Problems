#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string A) {
    
    unordered_map<int,string> m;
    unordered_map<int,string> :: iterator it;
    int j=0;
    //unordered_set<string> s;
    for(int i=0;i<A.length();i++){
        if(m.find(A[i])==m.end()){
            m[j]+=A[i];
            cout<<j;
        }
        else{
            j++;
        }
    }
    int len=0;
    for(it=m.begin();it!=m.end();it++){
        string b = it->second;
        int c = b.length();
        if(len<c)
            len = c;
    }
    return len;
}

int main(){

    string s = {"abcabcbb"};
    cout<<lengthOfLongestSubstring(s);
}