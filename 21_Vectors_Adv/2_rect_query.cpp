#include <iostream>
#include <vector>
using namespace std;
int rect_sum(vector<vector<int>>&v , int l1 , int r1 , int l2 , int r2);
int main(){
    int n,m,l1,r1,l2,r2;
    cout<<"n : ";  cin>>n;
    cout<<"m : ";  cin>>m;
    vector<vector<int>>v(n,vector<int>(m));
    for(int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout<<"A"<<i<<j<<" : ";  cin>>v[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"l1 : ";  cin>>l1;
    cout<<"r1 : ";  cin>>r1;
    cout<<"l2 : ";  cin>>l2;
    cout<<"r1 : ";  cin>>r2;

    cout<<"Ans = "<<rect_sum(v,l1,r1,l2,r2);
    return 0;
}

int rect_sum(vector<vector<int>>&v , int l1, int r1, int l2 , int r2){
    int sum =0;
    // Prefix sum array .....
    for(int i=0; i<v.size(); i++){
        for(int j=1; j<v[0].size(); j++){
            v[i][j] += v[i][j-1];
        }
    }
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[0].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=l1; i<=l2; i++){
        if(r1 != 0){
            sum = sum + v[i][r2] - v[i][r1-1];
        }
        else{
            sum += v[i][r2];
        }
    }
    return sum;
}