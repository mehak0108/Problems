#include <iostream>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <unordered_set>
using namespace std;

void groupElements(int a[], int n){
  unordered_map<int, int> m;
  unordered_map<int, int> :: iterator it;
  int j,k=0;

  for(int i=0;i<n;i++){
    m[a[i]]++;
    cout<<m[a[i]]<<" "<<a[i]<<endl;

  }
      
  for(it = m.begin();it!=m.end();it++){
    j=0;
    while(j<it->second){
      a[k] = it->first;
      cout<<a[k]<<" ";
      k++;
      j++;
    }
        
  }
  for(int i=0;i<n;i++)
      cout<<a[i]<<" ";
}


int main(){
   int arr[] = {4, 6, 9, 2, 3, 4, 9, 6, 10, 4};
   int n = sizeof(arr)/sizeof(arr[0]);
   groupElements(arr, n);
   return 0;
}
