#include<iostream>
using namespace std;
int main(){
    int m , n;
    cout<<"Enter the value of m : ";
    cin>>m;
    cout<<"Enter the value of n : ";
    cin>>n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if((i+j)%2==0){
                cout<<"1 ";
            }
            else{
                cout<<"2 ";
            }
        }
        cout<<endl;
    }
    return 0;
}