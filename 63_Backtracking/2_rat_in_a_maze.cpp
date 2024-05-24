#include <iostream>
#include <vector>
using namespace std;

bool canMove(int n, int i, int j, vector<vector<int>> &grid){
    return (i>=0 && j>=0 && i<n && j<n && grid[i][j]==1);
}

int findPaths(vector<vector<int>> &grid, int i, int j){
    int n=grid.size();
    int ans=0;

    //base case
    if(i==n-1 and j==n-1)  return 1;

    grid[i][j]=2;

    // Down
    if(canMove(n,i+1,j,grid)){
        ans+=findPaths(grid,i+1,j);
    }

    // Left
    if(canMove(n,i,j-1,grid)){
        ans+=findPaths(grid,i,j-1);
    }

    // Right
    if(canMove(n,i,j+1,grid)){
        ans+=findPaths(grid,i,j+1);
    }

    // Up
    if(canMove(n,i-1,j,grid)){
        ans+=findPaths(grid,i-1,j);
    }

    grid[i][j]=1;

    return ans;
}

int main(){
    vector<vector<int>> v={
        {1,1,1,1},
        {0,1,0,1},
        {0,1,1,1},
        {0,1,1,1}
    };
    cout<<findPaths(v,0,0);
    return 0;
}