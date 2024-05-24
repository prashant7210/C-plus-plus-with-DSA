#include <iostream>
using namespace std;
int main(){
    int array[]={3,1,2,4,0,6} , targetsum=5 , count=0;
    for(int i=0; i<6; i++){
        for(int j=i; j<6; j++){
            for(int k=j; k<6; k++){
                if(array[i]+array[j]+array[k]==targetsum){
                    count++;
                }
            }
        }
    }
    cout<<"Number of triplets = "<<count;
    return 0;
}