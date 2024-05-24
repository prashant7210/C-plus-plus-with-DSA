#include<iostream>
using namespace std;
int main()

{
int a,b,c;
    cout<<"Enter the value of a : ";
    cin>>a;
    cout<<"Enter the value of b : ";
    cin>>b;

    c=b;
    b=a;    //Swaping the value
    a=c;

    cout<<"The value of a is "<<a<<endl;
    cout<<"The value of b is "<<b<<endl;

    return 0;
}