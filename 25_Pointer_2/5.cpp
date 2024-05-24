#include <iostream>
using namespace std;
int main(){
    int x[2] = {1,2};
    int *ptr = &x[0];
    cout<<ptr<<" "<<ptr+1<<endl;
    cout<<*ptr++<<" ";
    cout<<*ptr<<endl;;
    int *p = &x[0];
    cout<<(*p)++<<endl;
    cout<<x[0]<<" "<<x[1];
    return 0;
}