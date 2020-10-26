#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> task(vector<int>&v){
    stack<int>s;
    int n = v.size();
    vector<int> z(n,-1);
    int prev;
    for(int i=0;i<n;i++){

        while(!s.empty() && s.top()>=v[i])
            s.pop();
        if(!s.empty())
            z[i] = s.top();
        s.push(v[i]);
    }
    return z;
}

int main(){
    vector<int> v{4, 5, 2, 10, 8};
    vector<int> res = task(v);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
}