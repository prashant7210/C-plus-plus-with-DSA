#include <iostream>
#include <vector>
using namespace std;
int rect_sum(vector<vector<int>>&v , int l1 , int r1 , int l2 , int r2);
int main(){
    int n,m,l1,r1,l2,r2;
    cout<<"n : ";   cin>>n;
    cout<<"m : ";   cin>>m;
    vector<vector<int>>v(n,vector<int>(n));
    cout<<"Enter elements :\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<"A"<<i<<j<<" : ";
            cin>>v[i][j];
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
    cout<<"r2 : ";  cin>>r2;
    cout<<"Sum = "<<rect_sum(v,l1,r1,l2,r2);
    return 0;
}

int rect_sum(vector<vector<int>>&v , int l1 , int r1 , int l2 , int r2){
    int sum=0;
    for(int i=l1; i<=l2; i++){
        for(int j=r1; j<=r2; j++){
            sum += v[i][j];
        }
    }
    return sum;
}