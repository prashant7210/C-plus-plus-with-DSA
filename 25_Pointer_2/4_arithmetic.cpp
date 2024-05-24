#include <iostream>
using namespace std;
int main(){
    int x=20;
    cout<<sizeof(x)<<endl;
    cout<<&x<<" "<<&x+2;
    return 0;
}