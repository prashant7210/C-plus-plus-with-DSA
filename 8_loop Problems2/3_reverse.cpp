#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    cout<<"Reverse of the number is ";
    
    while(n>0){
        cout<<(n%10);
        n/=10;
    }
    return 0;
}