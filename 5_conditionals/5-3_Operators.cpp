#include<iostream>
using namespace std;
int main(){
    int marks ;
    cout<<"Marks : ";
    cin>>marks;

    if(marks>33){
        cout<<"Pass.";
    }
    else{
        cout<<"Fail.";
    }

    marks>33? cout<<"\nPass." : cout<<"\nFail.";   // Ternary Operator....
    return 0;
}