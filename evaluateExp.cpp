#include <iostream>
#include <cctype>
#include <stack>
#include <vector>
#include <string>
using namespace std;


int ans(int a,int b, char c){
    switch(c){
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            if(b == 0)
                return 0;
            else
                return a/b;
        
    }
}
int evalRPN(vector<string> &A) {

    stack<int> s;
    for(int i=0;i<A.size();i++){
        char ch = A[i][0];
        string st = A[i];
        if(st!="+" && st!="-" && st!="*" && st!="/"){
            //int f = convert(st);
            //cout<<st<<endl;
            s.push(stoi(st));
        }
        else{
            int a = s.top();s.pop();
            int b = s.top();s.pop();
            int c = ans(b,a,ch);
            s.push(c);
        }
    }
    
    return s.top();
}


int main(){
    vector<string> v{"-2", "-1", "2", "+", "-1", "-", "-", "2", "-2", "1", "-", "+", "-", "-2", "-2", "-", "-1", "2", "-2", "-", "-2", "-1", "+", "1", "1", "-", "-1", "+", "1", "*", "*", "2", "+", "*", "-", "-2", "1", "-2", "*", "+", "-2", "*", "1", "*", "-", "*", "*"};
    cout<<evalRPN(v);
}