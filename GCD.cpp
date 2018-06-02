#include <iostream>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    while(a){
        int temp = b%a;
        b = a;
        a = temp; 
    }

    cout<<b;
}