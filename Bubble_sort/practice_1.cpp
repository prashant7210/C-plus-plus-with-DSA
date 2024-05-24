#include <iostream>
using namespace std;
void bubble_sort(int *arr, int n){
    for(int i=0; i<n; i++){
        bool flag=false;
        for(int j=0; j<n-i-1; j++){
            if(*(arr+j+1) < *(arr+j)){
                swap(*(arr+j+1),*(arr+j));
                flag = true;
            }
        }
        if(!flag)  break;
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    bubble_sort(arr,n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}