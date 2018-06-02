#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <string>
#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        bool a[n+1];
        memset(a,true,sizeof(a));
        for (int i = 2; i*i <= n; i++)
        {
            if (a[i] == true)
            {
                for (int p = 2*i; p<=n ; p+=i)
                {
                    a[p] = false;
                }
            }
        }
        for (int j = 2; j <= n; j++)
        {
            if (a[j]== true)
            {
                cout<<j<<" ";
            }
        }
    }
    return 0;
}