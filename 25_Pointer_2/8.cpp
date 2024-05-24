#include <iostream>
using namespace std;
int main(){
    int a[5] = {1,2,3,4,5};
    int (*ptr)[5] = &a;
    cout<<ptr<<endl;
    cout<<a<<endl;
    cout<<*ptr<<endl;
    cout<<*a<<endl;
    return 0;
}