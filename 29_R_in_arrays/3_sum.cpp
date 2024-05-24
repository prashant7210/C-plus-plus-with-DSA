#include <iostream>
using namespace std;
int f(int arr[], int idx, int n){
    if(idx==n)  return 0;
    return arr[idx]+f(arr,idx+1,n);
}
int main(){
    int n=5;
    int arr[] = {2,3,5,20,1};
    cout<<f(arr,0,n);
    return 0;
}