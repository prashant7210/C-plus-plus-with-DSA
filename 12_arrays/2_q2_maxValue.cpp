#include <iostream>
using namespace std;
int main(){
    int size , a[size];
    cout<<"Size of array : ";
    cin>>size;
    cout<<"Enter elemets : ";
    for(int i=0; i<size; i++){
        cin>>a[i];
    }

    int max = a[0];

    for(int i=1; i<size; i++){
        if(a[i]>max){
            max = a[i];
        }
    }

    cout<<"Max element : "<<max;
    return 0;
}