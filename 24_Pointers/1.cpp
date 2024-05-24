#include <iostream>
using namespace std;
int main(){
    int x=4;
    float y=7.5;
    int *ptrx = &x;
    float *ptry = &y;
    //Address
    cout<<ptrx<<" "<<ptry<<endl;
    //Derefrence
    cout<<*ptrx<<" "<<*ptry<<endl;
    return 0;
}