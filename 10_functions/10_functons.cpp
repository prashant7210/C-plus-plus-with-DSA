#include <iostream>
using namespace std;

int add(int num1 , int num2){
    int sum = num1 + num2;
    return sum;
}
int main(){
    int num1 , num2 ;
    cout<<"num1 : ";
    cin>>num1;

    cout<<"num2 : ";
    cin>>num2;

    cout<<"num1 + num2 = "<<add(num1,num2);
    return 0;
}