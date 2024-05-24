#include<iostream>
using namespace std;
int main(){
    int a , b;
    cout<<"a : ";
    cin>>a;
    cout<<"b : ";
    cin>>b;

    while(b>0){
        b/10;
        ::a*::a;
    } 
    return 0;
}