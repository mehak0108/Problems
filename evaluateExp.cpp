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
bool checkNum(string s){
    
    bool has_only_digits = true;
    for (size_t n = 0; n < s.length(); n++)
    {
       if (!isdigit( s[ n ] ))
       {
         has_only_digits = false;
         break;
     }
 }
 return has_only_digits;
}

int convert(string s){
    int j=1;
    int sum=0;
    for(int i=0;i<s.length();i++){
        int c = s[i]-48;
        sum = sum*j + c;
        j=j*10;
    }
    return sum;
}
int evalRPN(vector<string> &A) {

    stack<int> s;
    for(int i=0;i<A.size();i++){
        char ch = A[i][0];
        int no = ch-'0';
        string st = A[i];
        if(checkNum(st)){
            int f = convert(st);
            cout<<st<<endl;
            s.push(f);
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