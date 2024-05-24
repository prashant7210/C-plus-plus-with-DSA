#include <iostream>
using namespace std;

int add(int a , int b , int c=5){
    return a+b+c;
}
int main(){
    cout<<add(1,3)<<endl;
    cout<<add(1,4,6)<<endl;
    return 0;
}