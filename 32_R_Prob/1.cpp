#include <iostream>
using namespace std;
int f(int a,int b){
    if(b==0)  return a;
    if(a>b)  f(b,a%b);
    else  f(a,b%a);
}
int main(){
    int a,b;
    cout<<"a : ";  cin>>a;
    cout<<"b : ";  cin>>b;
    cout<<"GCD = "<<f(a,b);
    return 0;
}