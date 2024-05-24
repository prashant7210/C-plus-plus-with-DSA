#include<iostream>
using namespace std;
int main(){
    int m , n;
    cout<<"Enter the number of row : ";
    cin>>m;
    cout<<"Enter the number of column : ";
    cin>>n;

    for(int i=1; i<=m; i++){
        if((i==1)||(i==m)){
            for(int j=1; j<=n; j++){
                cout<<"* ";
            }
        }
        else{
    for(int j=1; j<=n; j++){
        if((j==1)||(j==n)){
            cout<<"* ";
        }
        else{
            cout<<"  ";
        }
    }
    }
    cout<<endl;
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(i==1||i==m||j==1||j==n){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
    return 0;
}