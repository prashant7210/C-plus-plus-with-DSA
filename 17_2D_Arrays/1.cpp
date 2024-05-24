#include <iostream>
using namespace std;
int main(){
    int r , c;
    cout<<"Row : ";
    cin>>r;
    cout<<"Column : ";
    cin>>c;
    int a[r][c];
    cout<<"Enter elements : \n";
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<"A"<<i<<j<<" : ";
            cin>>a[i][j];
        }
        cout<<endl;
    }
    cout<<"Matrix : \n";
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}