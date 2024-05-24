#include <iostream>
using namespace std;
int main(){
    int count = 0 , array[]={3,4,6,7,1};
    int targetsum = 7;

    for(int i=0; i<5; i++){
        for(int j=i; j<5; j++){
            if(array[i]+array[j]==targetsum){
                count++;
            }
        }
    }
    cout<<"Number of pairs = "<<count;
    return 0;
}