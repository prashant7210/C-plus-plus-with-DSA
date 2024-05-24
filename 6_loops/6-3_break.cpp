#include<iostream>
using namespace std;
int main(){

    // While loop
    int i = 5;
    while(true){
        if(i%7 == 0){
            cout<<"The first multiple of 5 which is also multiple of 7 (LCM of 5 and 7) is "<<i;
            break;
        }

        else{
            i += 5;
        }
    }

    // for loop
    for(i = 5; ; i += 5 ){
        if(i%7 == 0){
            cout<<"\nThe first multiple of 5 which is also multiple of 7 (LCM of 5 and 7) is "<<i;
            break;
        }

        else{
            i += 5;
        }
    }
    return 0;
}