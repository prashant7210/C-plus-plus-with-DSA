#include <iostream>
using namespace std;
int f(int n){
    if(n<10)  return n;
    return (n%10)+f(n/10);
}
int main(){
    int n;
    cout<<"n : ";  cin>>n;
    cout<<f(n);
    return 0;
}