#include <iostream>
#include <vector>
using namespace std;

void display(vector<vector<int>> &grid){
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid.size(); j++){
            cout<<grid[i][j]<<"     ";
        }
        cout<<endl;
    }
    cout<<"**************\n";
}

bool knightTour(vector<vector<int>> &grid, int i, int j, int n, int c){
    // base case
    if(i<0 || j<0 || i>=n || j>=n || grid[i][j]!=-1)  return false;
    if(c==n*n-1){
        grid[i][j]=c;
        display(grid);
        return true;
    }

    // Recursive case and self work
    grid[i][j]=c;
    if(knightTour(grid,i-1,j-2,n,c+1))  return true;
    if(knightTour(grid,i-1,j+2,n,c+1))  return true;
    if(knightTour(grid,i-2,j-1,n,c+1))  return true;
    if(knightTour(grid,i-2,j+1,n,c+1))  return true;
    if(knightTour(grid,i+1,j-2,n,c+1))  return true;
    if(knightTour(grid,i+1,j+2,n,c+1))  return true;
    if(knightTour(grid,i+2,j-1,n,c+1))  return true;
    if(knightTour(grid,i+2,j+1,n,c+1))  return true;
    grid[i][j]=-1;
    return false;
}

int main(){
    vector<vector<int>> v(6,vector<int>(6,-1));
    knightTour(v,0,0,6,0);
    return 0;
}