#include <iostream>
using namespace std;
int main(){
    int r , c;
    cout<<"r : ";  cin>>r;
    cout<<"c : ";  cin>>c;
    int A[r][c] , AT[c][r];
    cout<<"Enter elements : \n";
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<"A"<<i<<j<<" : ";  cin>>A[i][j];
        }
        cout<<endl;
    }

    for(int i=0; i<c; i++){
        for(int j=0; j<r; j++){
            AT[i][j] = A[j][i];
        }
    }

    cout<<"Transpose of the matrix : \n";
    for(int i=0; i<c; i++){
        for(int j=0; j<r; j++){
            cout<<AT[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}