#include<iostream>   //sum of n natural numbers
using namespace std;
int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int sum = 0;
    int i = 1;  // loop variable
    while(i<=n){
        sum += i;  // sum = sum + i
        i++;
    }

    cout<<"The sum of first n natural numbers is "<<sum<<endl;
                    // OR
    cout<<"The sum of first n natural numbers is "<<(((n)*(n+1))/2);  // Pre knowledge!!
   
    return 0;
}