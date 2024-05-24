#include <iostream>
using namespace std;
int main(){
    int a[]={1,2,3,4,5,4,3,2,1};
    for(int i=0; i<9; i++){
        for(int j=i+1; j<9; j++){
            if(a[i]==a[j]){
                a[i]=a[j]=-1;
            }
        }
    }
    for(int i=0; i<9; i++){
        if(a[i]!=-1){
            cout<<"Unique number = "<<a[i]<<" at index = "<<i;
        }
    }
    return 0;
}