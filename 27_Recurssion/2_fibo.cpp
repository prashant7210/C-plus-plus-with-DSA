#include <iostream>
using namespace std;
int f(int n){
    if(n==1 || n==0)  return n;
    return f(n-2) + f(n-1);
}
int main(){
    int n;
    cout<<"n : ";  cin>>n;
    cout<<f(n);
    return 0;
}