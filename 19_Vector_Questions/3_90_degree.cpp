#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void rotate(vector<vector<int>>&v);
int main(){
    int n;
    cout<<" n : ";
    cin>>n;
    vector<vector<int>>v(n,vector<int>(n));
    cout<<"Enter elements\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<"A"<<i<<j<<" : ";
            cin>>v[i][j];
        }
    }

    rotate(v);
    cout<<"Rotated matrix\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

void rotate(vector<vector<int>>&v){
    // Transpose
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<i; j++){
            swap(v[i][j],v[j][i]);
        }
    }

    for(int i=0; i<v.size(); i++){
        reverse(v[i].begin() , v[i].end());
    }
}