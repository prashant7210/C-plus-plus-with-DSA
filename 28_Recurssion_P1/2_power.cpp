#include <iostream>
using namespace std;
int f(int p, int q){
    if(q==0)  return 1;
    return p*f(p,q-1);
}
int main(){
    int p,q;
    cout<<"p : ";  cin>>p;
    cout<<"q : ";  cin>>q;
    cout<<"p^q = "<<f(p,q);
    return 0;
}