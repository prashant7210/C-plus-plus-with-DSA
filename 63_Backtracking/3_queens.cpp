#include <iostream>
#include <vector>
using namespace std;

bool canPlaceQueen(int row, int col, vector<vector<int>> &grid){
    // checking vertical attack
    for(int i=row-1; i>=0; i--){
        if(grid[i][col]==1)  return false;
    }

    // checking left diagonal attack
    for(int i=row-1,j=col-1; i>=0,j>=0; i--,j--){
        if(grid[i][j]==1)  return false;
    }

    // checking right diagonal atatck
    for(int i=row-1,j=col+1; i>=0,j<grid.size(); i--,j++){
        if(grid[i][j]==1)  return false;
    }
    return true;
}

void display(vector<vector<int>> & grid){
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid.size(); j++){
            cout<<grid[i][j]<<"  ";
        }
        cout<<"\n";
    }
    cout<<"**********\n";
    return;
}

void placingQueens(int row, int n, vector<vector<int>> &grid){
    // base case
    if(row==n){
        display(grid);
        return;
    }

    // Recursive case and self work
    for(int col=0; col<grid.size(); col++){
        // we will move to all columns
        if(canPlaceQueen(row,col,grid)){
            grid[row][col]=1;
            placingQueens(row+1,n,grid);
            grid[row][col]=0;
        }
    }
}

int main(){
    vector<vector<int>> v(4,vector<int>(4,0));
    placingQueens(0,4,v);
    return 0;
}