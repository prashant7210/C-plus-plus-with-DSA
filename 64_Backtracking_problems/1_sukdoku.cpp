#include <iostream>
#include <vector>
using namespace std;

bool canPlaceDigit(vector<vector<int>> &grid, int row, int col, char d){
    // Vertical check
    for(int i=0; i<9; i++){
        if(grid[i][col]==d)  return false;
    }

    // Horizontal check
    for(int j=0; j<9; j++){
        if(grid[row][j]==d)  return false;
    }

    // Checking cells
    int r=(row/3)*3;
    int c=(col/3)*3;
    for(int i=r; i<r+3; i++){
        for(int j=c; j<c+3; j++){
            if(grid[i][j]==d)  return false;
        }
    }
    return true;
}


bool solve(vector<vector<int>> &board, int row, int col){
    // base case
    if(col==9)  return solve(board,row+1,0);
    if(row==9)  return true;
    

    if(board[row][col]==0){
        for(int num=1; num<=9; num++){
            if(canPlaceDigit(board,row,col,num)){
                board[row][col]=num;
                bool ans=solve(board,row,col+1);
                if(ans)  return true;
                else  board[row][col]=0;
            }
        }
        return false;
    }
    else  return solve(board,row,col+1);
}

int main(){
    vector<vector<int>> v={
        {4,5,0,0,0,0,0,0,0},
        {0,0,2,0,7,0,6,3,0},
        {0,0,0,0,0,0,0,2,8},

        {0,0,0,9,5,0,0,0,0},
        {0,8,6,0,0,0,2,0,0},
        {0,2,0,6,0,0,7,5,0},

        {0,0,0,0,0,0,4,7,6},
        {0,0,0,0,4,5,0,0,0},
        {0,0,8,0,0,9,0,0,0}
    };
    solve(v,0,0);
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout<<v[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}