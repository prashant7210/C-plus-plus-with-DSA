#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> create_spiral(int n);
int main(){
    int n;
    cout<<"n : ";   cin>>n;
    vector<vector<int>>matrix(n,vector<int>(n));
    matrix = create_spiral(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

vector<vector<int>> create_spiral(int n){
    int left=0 , right=n-1 , top=0 , bottom=n-1 , direction=0 , c=1;
    vector<vector<int>>v(n,vector<int>(n));
    while(top<=bottom && left<=right){
        if(direction==0){
            for(int j=left; j<=right; j++){
                v[top][j] = c++;
            }
            top++;
        }

        else if(direction==1){
            for(int i=top; i<=bottom; i++){
                v[i][right] = c++;
            }
            right--;
        }

        else if(direction==2){
            for(int j=right; j>=left; j--){
                v[bottom][j] = c++;
            }
            bottom--;
        }

        else{
            for(int i=bottom; i>=top; i--){
                v[i][left] = c++;
            }
            left++;
        }
        direction = (direction+1)%4;
    }
    return v;
}