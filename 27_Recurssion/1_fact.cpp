#include <iostream>
using namespace std;
int f(int n){
    if(n==1)  return 1;
    return n*f(n-1);
}
int main(){
    int n;
    cout<<"n : ";  cin>>n;
    int ans = f(n);
    cout<<"n! = "<<ans;
    return 0;
}