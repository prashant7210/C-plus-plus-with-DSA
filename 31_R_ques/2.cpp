#include <iostream>
using namespace std;
void f(int n, int k){
    if(k==0)  return;
    f(n,k-1);
    cout<<(n*k)<<" ";
}
int main(){
    int n,k;
    cout<<"n : ";  cin>>n;
    cout<<"k : ";  cin>>k;
    f(n,k);
    return 0;
}