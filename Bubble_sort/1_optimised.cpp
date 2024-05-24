#include <iostream>
using namespace std;
int main(){
    int arr[]={7,5,2,9,2,0,1,-1} , n=8 , flag=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                flag=1;
                swap(arr[j],arr[j+1]);
            }
        }
        if(flag==0)  break;
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}