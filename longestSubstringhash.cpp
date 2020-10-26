#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring(string a) {
    
     int max=0;
   unordered_map< char, int> x;
   int s;
   
   int count = 0;
   for(int i=0; i<a.length(); i++){
       if(x.find(a[i])==x.end()){
           count++;
           x[a[i]] = i;
           if(max<count){
               max = count;
           }
       }
       else{
           count = count - x.find(a[i])->second;
           int t =  x.find(a[i])->second;
           i=t;
           while(t--){
               x.erase(a[t]);
           }

       }
   }
   return max;

    /*unordered_map<int,string> m;
    unordered_map<int,string> :: iterator it;
    int j=0;
    
    for(int i=0;i<A.length();i++){
        
        if(m.find(A[i])==m.end()){
            m[j]+=A[i];
            cout<<j;
        }
        else{
            i=j;
            j++;

        }
    }
    int len=0;
    for(it=m.begin();it!=m.end();it++){
        string b = it->second;
        cout<<b;
        int c = b.length();
        if(len<c)
            len = c;
    }
    return len;*/
}

int main(){

    string s = {"abcbse"};
    cout<<lengthOfLongestSubstring(s);
}