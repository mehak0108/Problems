#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int maxPoints(vector<int> &A, vector<int> &B) {
    
    unordered_map<pair<int,int>,int> m;
    int n = A.size();
    
    if(n < 2)
        return n;
    int i;
    int maxPoint=0;
    int curMax, overlapPoints, verticalPoints;
    for(i=0;i<n;i++){
        curMax = overlapPoints = verticalPoints = 0;
        for(int j=i+1;j<n;j++){
            if(A[i]==A[j]==B[i]==B[j]){
               overlapPoints++;
            }
            else if((A[j]-A[i])==0){
                verticalPoints++;
            }
            else{
                int ydiff = B[j]-B[i];
                int xdiff = A[j]-A[i];
                int g = __gcd(ydiff,xdiff);
                ydiff/=g;
                xdiff/=g;
                m[make_pair(ydiff,xdiff)]++;
                curMax = max(curMax, m[make_pair(ydiff, xdiff)]);
            }
            curMax = max(curMax, verticalPoints);
        }
        maxPoint = max(maxPoint, curMax + overlapPoints + 1);
        m.clear();
    }
    
    return maxPoint;
}

int main(){
    vector<int> A = {1,2};
    vector<int> B= {1,2};
    cout<<maxPoints(A,B);
}
