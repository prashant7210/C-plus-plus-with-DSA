#include<iostream>
using namespace std;
int main(){
    int m , n;
    cout<<"Enter the value of m : ";
    cin>>m;
    cout<<"Enter the value of n : ";
    cin>>n;

    for(int i=1; i<=m; i++){
        if(i%2==0){
            for(int j=1; j<=n; j++){
                if(j%2==0){
                    cout<<"1 ";
                }
                else{
                    cout<<"2 ";
                }
            }
        }
    
        else{
            for(int j=1; j<=n; j++){
                if(j%2==0){
                    cout<<"2 ";
                }
                else{
                    cout<<"1 ";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}