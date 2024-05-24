#include <iostream>
using namespace std;
int main (){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int sum = 0;
 
    do{                  //********** Not Running ************
        int i;
        cin>>i;
        sum += i;
        n--;
    }while(n>0);

    cout<<sum;
    return 0;
}