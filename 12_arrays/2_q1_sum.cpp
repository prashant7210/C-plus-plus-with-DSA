#include<iostream>
using namespace std;
int main(){
    int size , a[size] , sum=0;
    cout<<"Size of array : ";
    cin>>size;
    cout<<"Enter elemets : ";
    for(int i=0; i<size; i++){
        cin>>a[i];
    }
    
    for(int j=0; j<size; j++){
        sum += a[j];
    }

    cout<<"Sum of elements of array = "<<sum;
    return 0;
}