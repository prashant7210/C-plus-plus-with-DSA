#include <iostream>
#include <vector>
using namespace std;

void display(vector<vector<int>> &grid, int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<grid[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<"*************"<<endl;
}

bool canPlaceKnights(vector<vector<int>> &grid, int m, int n, int row, int col){
    if(row-2>=0 && col+1>=0 && row-2<m && col+1<n && grid[row-2][col+1]==1)  return false;
    if(row-2>=0 && col-1>=0 && row-2<m && col-1<n && grid[row-2][col-1]==1)  return false;
    if(row-1>=0 && col-2>=0 && row-1<m && col-2<n && grid[row-1][col-2]==1)  return false;
    if(row-1>=0 && col+2>=0 && row-1<m && col+2<n && grid[row-1][col+2]==1)  return false;
    return true;
}

void knights(vector<vector<int>> &grid, int m, int n, int row, int col, int k){
    // base cases
    if(k==0){      // All knights are placed
        display(grid,m,n);
        return;
    }
    if(row==m)  return;

    // Recursive cases and self work
    if(col==n){
        knights(grid,m,n,row+1,0,k);
        return;
    }
    for(int i=row; i<m; i++){
        for(int j=(i==row?col:0); j<n; j++){
            if(canPlaceKnights(grid,m,n,i,j)){
                grid[i][j]=1;
                knights(grid,m,n,i,j+1,k-1);
                grid[i][j]=0;
            }
        }
    }
}

int main(){
    vector<vector<int>>v(3,vector<int>(3,0));
    knights(v,3,3,0,0,5);
    return 0;
}