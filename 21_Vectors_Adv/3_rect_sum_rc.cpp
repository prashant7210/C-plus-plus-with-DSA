#include <iostream>
#include <vector>
using namespace std;
int rect_sum(vector<vector<int>>&v , int l1 , int r1 , int l2 , int r2);
int main(){
    int m,n,l1,l2,r1,r2;
    cout<<"m : ";  cin>>m;
    cout<<"n : ";  cin>>n;
    vector<vector<int>>v(m,vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<"A"<<i<<j<<" : ";   cin>>v[i][j];
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"l1 : ";  cin>>l1;
    cout<<"r1 : ";  cin>>r1;
    cout<<"l2 : ";  cin>>l2;
    cout<<"r2 : ";  cin>>r2;
    cout<<"Ans = "<<rect_sum(v,l1,r1,l2,r2);
    return 0;
}

int rect_sum(vector<vector<int>>&v , int l1 , int r1 , int l2 , int r2){
    int sum = 0;
    //Prefix sum over row...
    for(int i=0; i<v.size(); i++){
        for(int j=1; j<v[0].size(); j++){
            v[i][j] += v[i][j-1];
        }
    }
    
    //prefix sum over columns...
    for(int i=1; i<v.size(); i++){
        for(int j=0; j<v[0].size(); j++){
            v[i][j] += v[i-1][j];
        }
    }
    //printing prefix sum array...
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[0].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    int top_sum=0 , left_sum=0 , topleft_sum=0;
    if(l1!=0) top_sum = v[l1-1][r2];
    if(r1!=0) left_sum = v[l2][r1-1];
    if(l1!=0 && r1!=0) topleft_sum = v[l1-1][r1-1];
    return (v[l2][r2] - top_sum - left_sum + topleft_sum);
}