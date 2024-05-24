#include <iostream>
#include <vector>
using namespace std;
int max_ones(vector<vector<int>>&v);
int main(){
    int n,m;
    cout<<"m : ";   cin>>m;
    cout<<"n : ";   cin>>n;
    vector<vector<int>>vec(m,vector<int>(n));
    cout<<"Enter elements : \n";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<"A"<<i<<j<<" : ";
            cin>>vec[i][j];
        }
    }

    int result = max_ones(vec);
    cout<<"Reslut = "<<result;
    return 0;
}

int max_ones(vector<vector<int>>&v){
    int max_ones_number = INT16_MIN;
    int max_ones_row = -1;
    int column = v[0].size();
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            if(v[i][j]==1){
                int number_of_ones = column - j;
                if(number_of_ones>max_ones_number){
                    max_ones_number = number_of_ones;
                    max_ones_row = i;
                }
                break;
            }
        }
    }
    return max_ones_row;
}