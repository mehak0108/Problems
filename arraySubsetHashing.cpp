#include <iostream>
#include <unordered_map>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

 
/* Return 1 if arr2[] is a subset of 
arr1[] */
bool isSubset(int arr1[], int arr2[], 
                        int m, int n)
{
    int val =0;
    unordered_map<int,int> umap;
    unordered_map<int,int> :: iterator it;
    
    for(int i=0;i<m;i++)
        umap[arr1[i]] = val++;
    
    for(int j=0;j<n;j++){
        if(umap.find(arr2[j]) == umap.end())
            return 0;      
    }
}
 
// Driver code
int main()
{
    int arr1[] = {11, 1, 13, 21, 3, 7};
    int arr2[] = {11, 3, 7, 1};
 
    int m = sizeof(arr1)/sizeof(arr1[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]);
 
    if(isSubset(arr1, arr2, m, n))
        printf("arr2[] is subset of arr1[] ");
    else
        printf("arr2[] is not a subset of arr1[]");     
 
    getchar();
    return 0;
}
