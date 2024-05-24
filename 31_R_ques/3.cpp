#include <iostream>
using namespace std;
int f(int n){
    if(n<1)  return 0;
    return (n%2==0?-n:n)+f(n-1);
}
int main(){
    int n;
    cout<<"n : ";
    cin>>n;
    cout<<f(n);
    return 0;
}