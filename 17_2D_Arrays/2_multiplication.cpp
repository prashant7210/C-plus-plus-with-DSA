#include <iostream>
using namespace std;
int main(){
    int r1,c1,r2,c2;
    cout<<"r1 : ";  cin>>r1;
    cout<<"c1 : ";  cin>>c1;
    int A[r1][c1];
    cout<<"Enter elements : ";
    for(int i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            cin>>A[i][j];
        }
    }

    cout<<"r2 : ";  cin>>r2;
    cout<<"c2 : ";  cin>>c2;
    int B[r2][c2];
    cout<<"Enter elements : ";
    for(int i=0; i<r2; i++){
        for(int j=0; j<c2; j++){
            cin>>B[i][j];
        }
    }
    int C[r1][c2];
    if(c1!=r2){
        cout<<"Matrix multiplication not possible fo this input...";
    }
    else{
        cout<<"Multiplied matrix : \n";
        for(int i=0; i<r1; i++){
            for(int j=0; j<c2; j++){
                int value = 0;
                for(int k=0; k<r2; k++){
                    value += A[i][k]*B[k][j];
                }
                C[i][j] = value;
            }
        }
        
        for(int i=0; i<r1; i++){
            for(int j=0; j<c2; j++){
                cout<<C[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}