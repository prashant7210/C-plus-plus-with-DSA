#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> pascle_triangle(int n){
    vector<vector<int>> pascle(n);
    for(int i=0; i<n; i++){
        pascle[i].resize(i+1);
        for(int j=0; j<=i; j++){
            if(j==0 || j==i){
                pascle[i][j] = 1;
            }
            else{
                pascle[i][j] = pascle[i-1][j] + pascle[i-1][j-1];
            }
        }
    }
    return pascle;
}
int main(){
    int n;
    cout<<"n : ";
    cin>>n;
    vector<vector<int>> v;
    v = pascle_triangle(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }    
    return 0;
}