#include <iostream>
using namespace std;
void p(int *arr , int n){
    for(int i=0; i<n; i++){
        cout<<*(arr+i)<<" ";
    }
}
int main(){
    int arr[5] = {1,2,3,4,5};
    p(arr,5);

    return 0;
}