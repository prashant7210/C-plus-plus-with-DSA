#include <iostream>
#include <vector>
using namespace std;
int leftmost_one_row(vector<vector<int>>&v){
    int leftmost_one = -1;
    int max_ones_row = -1;
    int j = v[0].size()-1;\
    // Find leftmost one in 0th row
    while(j>=0 && v[0][j]==1){
        leftmost_one = j;
        max_ones_row = 0;
        j--;
    }

    // Finding a one left to the leftmost one in 0th row
    for(int i=0; i<v.size(); i++){
        while(j>=0 && v[i][j]==1){
            leftmost_one = j;
            max_ones_row = i;
            j--;
        }
    }
    return max_ones_row;
}
int main(){
    int m,n;
    cout<<"(m,n) : ";
    cin>>m>>n;
    vector<vector<int>> v(m,vector<int>(n));
    cout<<"Enter elements\n";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<"A"<<i<<j<<" : ";
            cin>>v[i][j];
        }
    }
    cout<<"Ans = "<<leftmost_one_row(v);
    return 0;
}