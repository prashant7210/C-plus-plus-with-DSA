#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;

    int result = 0;
    for(int i=1; i<=n; i++){
        if(i%2==0){
            result -= i;
        }
        else{
            result += i;
        }
    }

    cout<<"The result is "<<result;
    return 0;
}