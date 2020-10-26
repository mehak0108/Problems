#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int checkRow(int a[][9]){
    unordered_set<int>s;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(a[i][j]!=-2 && s.find(a[i][j])!=s.end())
                return 0;
            s.insert(a[i][j]);
        }
        s.clear();
    }
    return 1;
}

int checkCol(int a[][9]){
    unordered_set<int>s;
    for(int j=0;j<9;j++){
        for(int i=0;i<9;i++){
            if(a[i][j]!=-2 && s.find(a[i][j])!=s.end())
                return 0;
            s.insert(a[i][j]);
        }
        s.clear();
    }
    return 1;
}

int checkBlock(int a[][9]){
    unordered_set<int>s;
    for(int i=0;i<9;i+=3){
        for(int j=0;j<9;j+=3){
            for(int k=i;k<i+3;k++){
                for(int l=j;l<j+3;l++){
                    if(a[k][l]!=-2 && s.find(a[k][l])!=s.end())
                        return 0;
                    s.insert(a[k][l]);
                }
            }
            s.clear();
        }
    }
    return 1;
}

int isValidSudoku(const vector<string> &A) {

    string s;
    
    int a[9][9];
    for(int i=0;i<9;i++){
        s = A[i];
        for(int j=0;j<9;j++){
            if(isdigit(s[j]))
                a[i][j] = s[j]-'0';
            else
                a[i][j] = -2;
        }
    }
    if(checkRow(a)==1 && checkCol(a)==1 && checkBlock(a)==1)
        return 1;
    return 0;
}


int main(){
   vector<string> a = {"....5..1.", ".4.3.....", ".....3..1", "8......2.", "..2.7....", ".15......", ".....2...", ".2.9.....", "..4......"};

   cout<<isValidSudoku(a);
}