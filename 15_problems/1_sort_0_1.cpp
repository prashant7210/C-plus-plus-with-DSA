#include <iostream>
using namespace std;
int main(){
    int  a[] = {0,1,0,1,0,1,0,1,1,0,1};
    for(int i=0; i<11; i++){
        for(int j=i+1; j<11; j++){
            if(a[i]>a[j]){
                int c = a[i];
                a[i] = a[j];
                a[j] = c;
            }
        }
    }
    cout<<"Sorted elelemts : ";
    for(int i=0; i<11; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}