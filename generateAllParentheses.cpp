#include <iostream>
#include <string>
#include <stack>
using namespace std;

int isMatchingPair(char character1, char character2)
{
 if (character1 == '(' && character2 == ')')
   return 1;
else if (character1 == '{' && character2 == '}')
   return 1;
else if (character1 == '[' && character2 == ']')
   return 1;
else
   return 0;
}
int isValid(string A) {

    stack<char> s;
    for(int i=0;i<A.length();i++){
        if(A[i] == '(' || A[i]=='[' || A[i]=='{'){
            cout<<A[i];
            s.push(A[i]);
            cout<<s.top();

        }
        if(A[i] == ')' || A[i]==']' || A[i]=='}' ){
            if(s.empty())
                return 0;
            else
                if ( !isMatchingPair(s.top(), A[i]) ){

                    return 0;
                }
                s.pop();
            }
        }
        if(!s.empty())
            return 0;
        else
            return 1;
    }


    int main(){

        string s = "{()}[]";
        cout<<isValid(s);

    }