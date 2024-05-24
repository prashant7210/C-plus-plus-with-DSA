#include <iostream>
#include <vector>
using namespace std;
void spiral(vector<vector<int>>&v);
int main(){
    int m,n;
    cout<<"m : ";   cin>>m;
    cout<<"n : ";   cin>>n;
    vector<vector<int>>v(m,vector<int>(n));
    cout<<"Enter elements\n";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<"A"<<i<<j<<" : ";
            cin>>v[i][j];
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    spiral(v);
    return 0;
}

void spiral(vector<vector<int>>&v){
    int left=0 , right=v[0].size()-1 , top=0 , bottom=v[0].size()-1 , direction=0;
    while(left<=right && top<=bottom){
        if(direction==0){
            for(int col=left; col<=right; col++){
                cout<<v[top][col]<<" ";
            }
            top++;
        }

        else if(direction==1){
            for(int row=top; row<=bottom; row++){
                cout<<v[row][right]<<" ";
            }
            right--;
        }

        else if(direction==2){
            for(int col=right; col>=left; col--){
                cout<<v[bottom][col]<<" ";
            }
            bottom--;
        }

        else if(direction==3){
            for(int row=bottom; row>=top; row--){
                cout<<v[row][left]<<" ";
            }
            left++;
        }
        direction = (direction+1)%4;
    }
}